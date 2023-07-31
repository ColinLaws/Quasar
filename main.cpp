
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

#include "Core/App.hpp"

// Set this to 1 to enable rdpq debug output.
// The demo will only run for a single frame and stop.
//#define DEBUG_RDP 0

// ;

// //static GLuint textures[4];



// static const GLfloat light_pos[8][4] = {
//     { 1, 1, 0, 0 },
//     { -1, 0, 0, 0 },
//     { 0, 0, 1, 0 },
//     { 0, 0, -1, 0 },
//     { 8, 3, 0, 1 },
//     { -8, 3, 0, 1 },
//     { 0, 3, 8, 1 },
//     { 0, 3, -8, 1 },
// };



// static const char *texture_path[4] = {
//     "rom:/circle0.sprite",
//     "rom:/diamond0.sprite",
//     "rom:/pentagon0.sprite",
//     "rom:/triangle0.sprite",
// };

// static sprite_t *sprites[4];
// static rdpq_font_t *fnt1;
// static model64_t *model;

using Quasar::Core::App;

static App *app;

// static Camera *camera;

//GLfloat objectX = 0.0f;

// void setup()
// {
    // fnt1 = rdpq_font_load("rom:/Pacifico.font64");
    // model = model64_load("rom:/fractal-pyramid.model64");

    

    // for (uint32_t i = 0; i < 4; i++)
    // {
    //     sprites[i] = sprite_load(texture_path[i]);
    // }

    
    
// }

// void set_light_positions(float rotation)
// {
//     glPushMatrix();
//     glRotatef(rotation*5.43f, 1, 0, 1);


//     for (int i = 0; i < 7; i++)
//     {
//         glLightfv(GL_LIGHT0 + i, GL_POSITION, light_pos[i]);
//     }
    
//     glPopMatrix();
// }

// void render()
// {

//     // camera->transform(&camera);

//     // Set some global render modes that we want to apply to all models
//     glEnable(GL_LIGHTING);
//     glEnable(GL_NORMALIZE);
//     glEnable(GL_DEPTH_TEST);
//     glEnable(GL_CULL_FACE);

//     set_light_positions(0.0f);

//     glEnable(GL_BLEND);
//     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
//     glPushMatrix();

//     glTranslatef(-0.5f, -0.5f, 0.0f);



//     glPopMatrix();

//     glDisable(GL_BLEND);

//     gl_context_end();
//     glFlush();

//     // rdpq_font_begin(RGBA32(0xED, 0xAE, 0x49, 0xFF));
//     // rdpq_font_position(20, 50);
//     // rdpq_font_print(fnt1, "");
//     // rdpq_font_end();

//     rdpq_detach_show();
// }

int main(void)
{
    app = new App();



//     setup();



    while (1)
    {
        app->Update();

        //controller_scan();
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

        //render();

        
    }
}
