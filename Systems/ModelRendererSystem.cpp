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

            glTranslatef(-0.0f, -0.0f, -2.0f);
            glRotatef(60.0f, 0.0f, 1.0f, 0.0f);
            glRotatef(60.0f, 1.0f, 0.0f, 0.0f);
            
            auto entityIds = entityManager->GetEntities<ModelComponent, TransformComponent>();

            for (uint16_t entityId : entityIds)
            {
                ModelComponent* modelComponent = entityManager->GetComponent<ModelComponent>(entityId);

                glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
                model64_draw(modelComponent->model);
            }

            glPopMatrix();
        }
    }
}
