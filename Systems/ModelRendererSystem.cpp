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
            

            auto entityIds = entityManager->GetEntities<ModelComponent, TransformComponent>();

            for (uint16_t entityId : entityIds)
            {
                glPushMatrix();
                ModelComponent* modelComponent = entityManager->GetComponent<ModelComponent>(entityId);


                TransformComponent* transformComponent = entityManager->GetComponent<TransformComponent>(entityId);

                

                glTranslatef(transformComponent->position[0], transformComponent->position[1], transformComponent->position[2]);
                
                transformComponent->rotation[1] += 5.0f;

                glRotatef(transformComponent->rotation[0], 1.0f, 0.0f, 0.0f);
                glRotatef(transformComponent->rotation[1], 0.0f, 1.0f, 0.0f);
                glRotatef(transformComponent->rotation[2], 0.0f, 0.0f, 1.0f);

                glColor4f(1.0f, 0.0f, 1.0f, 0.5f);

                model64_draw(modelComponent->model);

                glPopMatrix();
            }

            
        }
    }
}
