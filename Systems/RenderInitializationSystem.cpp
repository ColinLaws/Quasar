#include "GL/gl.h"
#include "GL/glu.h"
#include <GL/gl_integration.h>
#include "RenderInitializationSystem.hpp"
#include "../Components/ModelComponent.hpp"

using Quasar::Components::ModelComponent;

namespace Quasar
{
     namespace Systems
    {
        RenderInitializationSystem::RenderInitializationSystem()
        {
            static const GLfloat environment_color[] = { 0.1f, 0.03f, 0.2f, 1.f };
            GLfloat mat_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
            zbuffer = surface_alloc(FMT_RGBA16, display_get_width(), display_get_height());
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_diffuse);
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
        }

        void RenderInitializationSystem::Initialize(EntityManager* entityManager)
        {
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

            float light_radius = 5.0f;

            for (int i = 0; i < 7; i++)
            {
                glEnable(GL_LIGHT0 + i);
                glLightfv(GL_LIGHT0 + i, GL_DIFFUSE, light_diffuse[i]);
                glLightf(GL_LIGHT0 + i, GL_LINEAR_ATTENUATION, 2.0f/light_radius);
                glLightf(GL_LIGHT0 + i, GL_QUADRATIC_ATTENUATION, 1.0f/(light_radius*light_radius));
            }
        }

        void RenderInitializationSystem::Update(float deltaTime)
        {
            surface_t *disp = display_get();

            rdpq_attach(disp, &zbuffer);

            gl_context_begin();

            glClearColor(0.1f, 0.03f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            
            glMatrixMode(GL_MODELVIEW);
        }
    }
}
