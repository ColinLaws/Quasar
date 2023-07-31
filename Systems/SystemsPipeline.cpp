#include "libdragon.h"
#include "GL/gl.h"
#include <GL/glu.h>
#include <GL/gl_integration.h>
#include "SystemsPipeline.hpp"

namespace Quasar
{
    namespace Systems
    {
        SystemsPipeline::SystemsPipeline() 
        {
        }

        void SystemsPipeline::Update(float deltaTime)
        {
            UpdateGameplaySystems(deltaTime);
            UpdateRenderSystems(deltaTime);
        }

        void SystemsPipeline::RegisterGameplaySystem(System* system)
        {
            gameplaySystems.push_back(system);
        }

        void SystemsPipeline::RegisterRenderSystem(System* system)
        {
            renderSystems.push_back(system);
        }

        void SystemsPipeline::UpdateGameplaySystems(float deltaTime)
        {
            for (System* system : gameplaySystems)
            {
                system->Update(deltaTime);
            }
        }

        void SystemsPipeline::UpdateRenderSystems(float deltaTime)
        {
            for (System* system : renderSystems)
            {
                system->Update(deltaTime);
            }
        }
    }
}