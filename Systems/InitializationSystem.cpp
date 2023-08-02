#include "InitializationSystem.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/ModelComponent.hpp"

using Quasar::Components::TransformComponent;
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

            model64_t *model = model64_load("rom:/n64-logo.model64");

            ModelComponent* modelComponent = new ModelComponent(model);

            for (int row = 0; row < 4; row++)
            {
                for (int column = 0; column < 4; column++)
                {
                    uint16_t entityId = this->entityManager->CreateEntity();

                    this->entityManager->AddComponent<ModelComponent>(entityId, modelComponent);
                    
                    this->entityManager->AddComponent<TransformComponent>(entityId, 
                        new TransformComponent(
                            (column * 3.0f) - 4.0f, (row * 3.0f) - 4.0f, -8.0,
                            60, 60, 0,
                            1, 1, 1
                        )
                    );
                }
            }
        }

        void InitializationSystem::Update(float deltaTime)
        {
            
        }
    }
}
