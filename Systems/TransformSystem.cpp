#include "TransformSystem.hpp"

namespace Quasar
{
     namespace Systems
    {
        TransformSystem::TransformSystem()
        {
            
        }

        void TransformSystem::Initialize(EntityManager* entityManager)
        {
            this->entityManager = entityManager;
        }

        void TransformSystem::Update(float deltaTime)
        {
            
        }
    }
}
