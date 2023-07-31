#include "InitializationSystem.hpp"
#include "../Components/ModelComponent.hpp"

using Quasar::Components::ModelComponent;

namespace Quasar
{
     namespace Systems
    {
        InitializationSystem::InitializationSystem()
        {
            
        }

        void InitializationSystem::Initialize(EntityManager* entityManager)
        {
            this->entityManager = entityManager;

            uint16_t entityId = this->entityManager->CreateEntity();

            model64_t *model = model64_load("rom:/fractal-pyramid.model64");

            this->entityManager->AddComponent(entityId, new ModelComponent(model));
        }

        void InitializationSystem::Update(float deltaTime)
        {
            
        }
    }
}
