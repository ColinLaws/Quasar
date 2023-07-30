#include "ModelRendererSystem.hpp"

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
            
        }
    }
}
