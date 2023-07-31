#include "ModelRendererSystem.hpp"
#include "GL\GL.h"

namespace Quasar
{
     namespace Systems
    {
        ModelRendererSystem::ModelRendererSystem()
        {
            
        }

        void ModelRendererSystem::Initialize(EntityManager* entityManager)
        {
            this->entityManager = entityManager;
        }

        void ModelRendererSystem::Update(float deltaTime)
        {
            glPushMatrix();
            // 
            
            // glBegin(GL_TRIANGLE_STRIP);
            //     glNormal3f(0, 1, 0);
            //     glTexCoord2f(0, 0);
            //     glVertex3f(-0.5f, 0, -0.5f);
            //     glTexCoord2f(0, 1);
            //     glVertex3f(-0.5f, 0, 0.5f);
            //     glTexCoord2f(1, 0);
            //     glVertex3f(0.5f, 0, -0.5f);
            //     glTexCoord2f(1, 1);
            //     glVertex3f(0.5f, 0, 0.5f);
            // glEnd();

            glTranslatef(-0.0f, -0.0f, -2.0f);

            

            for (const ModelComponent& modelComponent : entityManager->modelComponents.items)
            {
                glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
                model64_draw(modelComponent.model);
            }

            glPopMatrix();
        }
    }
}
