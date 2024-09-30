#pragma once

#include "System.hpp"
#include "../Core/EntityManager.hpp"

using std::vector;
using Quasar::Systems::System;

namespace Quasar
{
     namespace Systems
    {
        class SystemsPipeline
        {
            public:
                SystemsPipeline();
                void Update(float deltaTime);

                // Registration must be sequential. Once made, a system cannot be unregistered.
                void RegisterGameplaySystem(System* system);
                void RegisterRenderSystem(System* system);

            private:
                void UpdateGameplaySystems(float deltaTime);
                void UpdateRenderSystems(float deltaTime);

            private:
                std::vector<System*> gameplaySystems;
                std::vector<System*> renderSystems;
        };
    }
}
