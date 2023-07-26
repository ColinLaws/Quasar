#include <libdragon.h>
#include <dragonfs.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/gl_integration.h>
#include <malloc.h>
#include <math.h>
#include <malloc.h>
#include "camera.h"
#include "decal.h"
#include "model64.h"
#include "Core/GameObject.hpp"

// Set this to 1 to enable rdpq debug output.
// The demo will only run for a single frame and stop.
#define DEBUG_RDP 0

// static uint32_t animation = 3283;
static camera_t camera;
static surface_t zbuffer;

//static GLuint textures[4];

static const GLfloat environment_color[] = { 0.1f, 0.03f, 0.2f, 1.f };

static const GLfloat light_pos[8][4] = {
    { 1, 3, 0, 0 },
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
static GameObject *gameObject;

void setup()
{
    fnt1 = rdpq_font_load("rom:/Pacifico.font64");
    model = model64_load("rom:/n64-logo.model64");

    camera.distance = -10.0f;
    camera.rotation = 0.0f;

    zbuffer = surface_alloc(FMT_RGBA16, display_get_width(), display_get_height());

    for (uint32_t i = 0; i < 4; i++)
    {
        sprites[i] = sprite_load(texture_path[i]);
    }

    float aspect_ratio = (float)display_get_width() / (float)display_get_height();
    float near_plane = 1.0f;
    float far_plane = 50.0f;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-near_plane*aspect_ratio, near_plane*aspect_ratio, -near_plane, near_plane, near_plane, far_plane);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, environment_color);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

    float light_radius = 5.0f;


    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse[0]);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 2.0f/light_radius);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 1.0f/(light_radius*light_radius));

    GLfloat mat_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_diffuse);

    // glFogf(GL_FOG_START, 5);
    // glFogf(GL_FOG_END, 20);
    // glFogfv(GL_FOG_COLOR, environment_color);

    // glGenTextures(4, textures);

    // GLenum min_filter = GL_LINEAR;

    // rdpq_texparms_t texparms = {0};
    // texparms.s.repeats = REPEAT_INFINITE;
    // texparms.t.repeats = REPEAT_INFINITE;

    // for (uint32_t i = 0; i < 4; i++)
    // {
    //     glBindTexture(GL_TEXTURE_2D, textures[i]);

    //     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    //     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter);

    //     glSpriteTextureN64(GL_TEXTURE_2D, sprites[i], &texparms);
    // }
}

void set_light_positions(float rotation)
{
    glPushMatrix();
    glRotatef(rotation*5.43f, 1, 0, 1);


    glLightfv(GL_LIGHT0, GL_POSITION, light_pos[0]);
    
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
    camera_transform(&camera);

    // Set some global render modes that we want to apply to all models
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    set_light_positions(0.0f);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // mesh_t *mesh = model64_get_mesh(model, 0);

    model64_draw(model);
    
    // model64_draw_mesh(model64_get_mesh(model, 4));
    // glDisable(GL_BLEND);

    gl_context_end();
    glFlush();

    // rdpq_font_begin(RGBA32(0xED, 0xAE, 0x49, 0xFF));
    // rdpq_font_position(20, 50);
    // rdpq_font_print(fnt1, "Shitty Titty Jelly Belly");
    // rdpq_font_end();

    rdpq_detach_show();
}

int main(void)
{
	debug_init_isviewer();
	debug_init_usblog();
    dfs_init(DFS_DEFAULT_LOCATION);

    display_init(RESOLUTION_320x240, DEPTH_16_BPP, 3, GAMMA_NONE, ANTIALIAS_RESAMPLE_FETCH_ALWAYS);

    rdpq_init();
    gl_init();

    gameObject = new GameObject();
    
    if (gameObject->id == 2) 
    {
        gl_close();
    }

#if DEBUG_RDP
    rdpq_debug_start();
    rdpq_debug_log(true);
#endif

    setup();

    controller_init();

    while (1)
    {
        controller_scan();
        struct controller_data pressed = get_keys_pressed();

        float y = pressed.c[0].y / 128.f;
        float x = pressed.c[0].x / 128.f;
        float mag = x*x + y*y;

        if (fabsf(mag) > 0.01f) {
            camera.distance += y * 0.2f;
            camera.rotation = camera.rotation - x * 1.2f;
        }

        render();

        //rspq_wait();
    }
}
