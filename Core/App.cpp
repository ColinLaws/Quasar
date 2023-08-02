#include "App.hpp"
#include "GL/gl.h"
#include "GL/glu.h"
#include <GL/gl_integration.h>
#include <dragonfs.h>
#include "../Systems/InitializationSystem.hpp"
#include "../Systems/ModelRendererSystem.hpp"
#include "../Systems/RenderInitializationSystem.hpp"
#include "../Systems/RenderUninitializationSystem.hpp"
#include "../Systems/TransformSystem.hpp"

using Quasar::Systems::ModelRendererSystem;
using Quasar::Systems::RenderInitializationSystem;
using Quasar::Systems::RenderUninitializationSystem;
using Quasar::Systems::InitializationSystem;
using Quasar::Systems::TransformSystem;

namespace Quasar
{
    namespace Core
    {
        App::App()
        {
            // debug_init_isviewer();
            // debug_init_usblog();
            dfs_init(DFS_DEFAULT_LOCATION);

            display_init(RESOLUTION_640x480, DEPTH_16_BPP, 3, GAMMA_NONE, ANTIALIAS_RESAMPLE_FETCH_ALWAYS);

            rdpq_init();
            gl_init();
            
            controller_init();

            // #if DEBUG_RDP
            //     rdpq_debug_start();
            //     rdpq_debug_log(true);
            // #endif

            systemsPipeline = new SystemsPipeline();
            entityManager = new EntityManager();

            this->Initialize();
        }

        void App::Initialize()
        {
            RegisterComponents();
            RegisterSystems();
        }

        void App::RegisterComponents()
        {
            ComponentCollection<TransformComponent> *transformCollection = new ComponentCollection<TransformComponent>();
            entityManager->RegisterComponentCollection<TransformComponent>(transformCollection);

            ComponentCollection<ModelComponent> *modelCollection = new ComponentCollection<ModelComponent>();
            entityManager->RegisterComponentCollection<ModelComponent>(modelCollection);
        }

        void App::RegisterSystems()
        {
            // Gameplay Systems
            InitializationSystem* initializationSystem = new InitializationSystem();
            initializationSystem->Initialize(entityManager);

            TransformSystem* transformSystem = new TransformSystem();
            transformSystem->Initialize(entityManager);

            systemsPipeline->RegisterGameplaySystem(initializationSystem);
            systemsPipeline->RegisterGameplaySystem(transformSystem);

            // Render Systems
            RenderInitializationSystem* renderInitializationSystem = new RenderInitializationSystem();
            renderInitializationSystem->Initialize(entityManager);

            RenderUninitializationSystem* renderUninitializationSystem = new RenderUninitializationSystem();
            renderUninitializationSystem->Initialize(entityManager);

            ModelRendererSystem* modelRendererSystem = new ModelRendererSystem();
            modelRendererSystem->Initialize(entityManager);

            systemsPipeline->RegisterRenderSystem(renderInitializationSystem);
            systemsPipeline->RegisterRenderSystem(modelRendererSystem);
            systemsPipeline->RegisterRenderSystem(renderUninitializationSystem);
        }

        void App::Update()
        {
            systemsPipeline->Update(0);

            //rspq_wait();
        }
    }
}
