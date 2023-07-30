
#include "decal.h"
#include "model64.h"
#include <libdragon.h>
#include <dragonfs.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/gl_integration.h>
#include <malloc.h>
#include <math.h>
#include <malloc.h>

// Set this to 1 to enable rdpq debug output.
// The demo will only run for a single frame and stop.
#define DEBUG_RDP 0

static surface_t zbuffer;

//static GLuint textures[4];

static const GLfloat environment_color[] = { 0.1f, 0.03f, 0.2f, 1.f };

static const GLfloat light_pos[8][4] = {
    { 1, 1, 0, 0 },
    { -1, 0, 0, 0 },
    { 0, 0, 1, 0 },
    { 0, 0, -1, 0 },
    { 8, 3, 0, 1 },
    { -8, 3, 0, 1 },
    { 0, 3, 8, 1 },
    { 0, 3, -8, 1 },
};

static const GLfloat light_diffuse[8][4] = {
    { 1.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 1.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 0.0f, 1.0f },
    { 1.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
};

static const char *texture_path[4] = {
    "rom:/circle0.sprite",
    "rom:/diamond0.sprite",
    "rom:/pentagon0.sprite",
    "rom:/triangle0.sprite",
};

static sprite_t *sprites[4];
static rdpq_font_t *fnt1;
static model64_t *model;

// static Camera *camera;

GLfloat objectX = 0.0f;

void setup()
{
    fnt1 = rdpq_font_load("rom:/Pacifico.font64");
    model = model64_load("rom:/fractal-pyramid.model64");

    zbuffer = surface_alloc(FMT_RGBA16, display_get_width(), display_get_height());

    for (uint32_t i = 0; i < 4; i++)
    {
        sprites[i] = sprite_load(texture_path[i]);
    }

    float aspect_ratio = (float)display_get_width() / (float)display_get_height();
    float near_plane = 0.125f;
    float far_plane = 50.0f;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-near_plane*aspect_ratio, near_plane*aspect_ratio, -near_plane, near_plane, near_plane, far_plane);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, environment_color);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

    float light_radius = 5.0f;

    for (int i = 0; i < 7; i++)
    {
        glEnable(GL_LIGHT0 + i);
        glLightfv(GL_LIGHT0 + i, GL_DIFFUSE, light_diffuse[i]);
        glLightf(GL_LIGHT0 + i, GL_LINEAR_ATTENUATION, 2.0f/light_radius);
        glLightf(GL_LIGHT0 + i, GL_QUADRATIC_ATTENUATION, 1.0f/(light_radius*light_radius));
    }

    // GLfloat mat_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    // glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_diffuse);
}

void set_light_positions(float rotation)
{
    glPushMatrix();
    glRotatef(rotation*5.43f, 1, 0, 1);


    for (int i = 0; i < 7; i++)
    {
        glLightfv(GL_LIGHT0 + i, GL_POSITION, light_pos[i]);
    }
    
    glPopMatrix();
}

void render()
{
    surface_t *disp = display_get();

    rdpq_attach(disp, &zbuffer);

    gl_context_begin();

    glClearColor(environment_color[0], environment_color[1], environment_color[2], environment_color[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    // camera->transform(&camera);

    // Set some global render modes that we want to apply to all models
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    set_light_positions(0.0f);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glPushMatrix();

    glTranslatef(-0.5f, -0.5f, 0.0f);

    model64_draw(model);

    glPopMatrix();

    glDisable(GL_BLEND);

    gl_context_end();
    glFlush();

    // rdpq_font_begin(RGBA32(0xED, 0xAE, 0x49, 0xFF));
    // rdpq_font_position(20, 50);
    // rdpq_font_print(fnt1, "");
    // rdpq_font_end();

    rdpq_detach_show();
}

int main(void)
{
	debug_init_isviewer();
	debug_init_usblog();
    dfs_init(DFS_DEFAULT_LOCATION);

    display_init(RESOLUTION_640x480, DEPTH_16_BPP, 3, GAMMA_NONE, ANTIALIAS_RESAMPLE_FETCH_ALWAYS);

    rdpq_init();
    gl_init();
    
#if DEBUG_RDP
    rdpq_debug_start();
    rdpq_debug_log(true);
#endif

    setup();

    controller_init();

    while (1)
    {
        controller_scan();
        // struct controller_data pressed = get_keys_pressed();
        // //struct controller_data held = get_keys_held();

        // float y = pressed.c[0].y / 128.f;
        // float x = pressed.c[0].x / 128.f;
        
        // // Squares of each component of a vector added together = its magnitude.
        // float mag = (x*x) + (y*y);

        // // Since I'm such a nice guy, I'll let the player set this in the menu. You're welcome, I love you.
        // float deadZone = 0.01f;

        // float sensitivity = 3.5f;

        // // If the magnitude of our stick exceeds the dead zone.
        // if (fabsf(mag) > deadZone) {
        //     camera.rotation[CAMERA_AXIS_X] += -y * sensitivity;
        //     camera.rotation[CAMERA_AXIS_Y] = camera.rotation[CAMERA_AXIS_Y] - (-x * sensitivity);
        // }

        // if (held.c->C_up && !held.c->C_down) {
        //     camera.position[CAMERA_AXIS_Z] -= 0.25f;
        // }
        // else if (!held.c->C_up && held.c->C_down) {
        //     camera.position[CAMERA_AXIS_Z] += 0.25f;
        // }

        render();

        //rspq_wait();
    }
}
