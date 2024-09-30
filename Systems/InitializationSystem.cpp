#include "InitializationSystem.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/ModelComponent.hpp"

using Quasar::Components::ModelComponent;
using Quasar::Components::TransformComponent;

namespace Quasar
{
    namespace Systems
    {
        InitializationSystem::InitializationSystem()
        {
        }

        void InitializationSystem::Initialize(EntityManager *entityManager)
        {
            this->entityManager = entityManager;

            model64_t *model = model64_load("rom:/n64-logo.model64");

            ModelComponent *modelComponent = new ModelComponent(model);

            uint16_t entityId = this->entityManager->CreateEntity();

            this->entityManager->AddComponent<ModelComponent>(entityId, modelComponent);

            this->entityManager->AddComponent<TransformComponent>(entityId,
                                                                  new TransformComponent(
                                                                      0, -9, -25.0,
                                                                      0, 0, 0,
                                                                      1, 1, 1));
        }

        void InitializationSystem::Update(float deltaTime)
        {
        }
    }
}
