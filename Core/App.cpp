#include "App.hpp"
#include "../Systems/ModelRendererSystem.hpp"
#include "../Systems/TransformSystem.hpp"

using Quasar::Systems::ModelRendererSystem;
using Quasar::Systems::TransformSystem;

namespace Quasar
{
    namespace Core
    {
        App::App()
        {
            systemsPipeline = new SystemsPipeline();
            entityManager = new EntityManager();
        }

        void App::Initialize()
        {
            TransformSystem* transformSystem = new TransformSystem();
            transformSystem->Initialize(entityManager);

            ModelRendererSystem* modelRendererSystem = new ModelRendererSystem();
            modelRendererSystem->Initialize(entityManager);

            // Gameplay Systems
            systemsPipeline->RegisterGameplaySystem(transformSystem);

            // Render Systems
            systemsPipeline->RegisterGameplaySystem(modelRendererSystem);
        }

        void App::Update()
        {
            systemsPipeline->Update(0);
        }
    }
}
