#include "ModelRendererSystem.hpp"
#include <GL/gl.h>

namespace Quasar
{
    namespace Systems
    {
        ModelRendererSystem::ModelRendererSystem()
        {
        }

        void ModelRendererSystem::Initialize(EntityManager *entityManager)
        {
            this->entityManager = entityManager;
        }

        void ModelRendererSystem::Update(float deltaTime)
        {
            auto entityIds = entityManager->GetEntities<ModelComponent>();

            ModelComponent *modelComponent = entityManager->GetComponent<ModelComponent>(entityIds[0]);

            // For every entityId we have
            for (uint16_t entityId : entityIds)
            {
                glPushMatrix();

                // Get the transform of the entity
                TransformComponent *transformComponent = entityManager->GetComponent<TransformComponent>(entityId);

                // Set the current spot we are drawing
                glTranslatef(transformComponent->position[0], transformComponent->position[1], transformComponent->position[2]);

                // Rotate for each axis in 3D space.
                glRotatef(transformComponent->rotation[0], 1.0f, 0.0f, 0.0f);
                glRotatef(transformComponent->rotation[1], 0.0f, 1.0f, 0.0f);
                glRotatef(transformComponent->rotation[2], 0.0f, 0.0f, 1.0f);

                // TODO: This is just some temporary color info.
                glColor4f(1.0f, 0, 0, 0.5f);

                model64_draw(modelComponent->model);

                glPopMatrix();
            }
        }
    }
}
