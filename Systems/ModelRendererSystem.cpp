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
            for (const ModelComponent& modelComponent : entityManager->modelComponents.items)
            {
                glColor3f(1.0f, 1.0f, 1.0f);
                model64_draw(modelComponent.model);
            }
        }
    }
}
