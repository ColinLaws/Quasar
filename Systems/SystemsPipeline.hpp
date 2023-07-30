#pragma once

#include "System.hpp"
#include "../Core/EntityManager.hpp"

using std::vector;
using Quasar::System::System;
using Quasar::Core::EntityManager;

namespace Quasar
{
    namespace System
    {
        class SystemsPipeline
        {
            public:
                SystemsPipeline();
                void Initialize();
        
                void Update(float deltaTime);

                // Registration must be sequential. Once made, a system cannot be unregistered.
                void RegisterGameplaySystem(System* system);
                void RegisterRenderSystem(System* system);

            private:
                void UpdateGameplaySystems(float deltaTime);
                void UpdateRenderSystems(float deltaTime);

            private:
                EntityManager* entityManager;
                std::vector<System*> gameplaySystems;
                std::vector<System*> renderSystems;
        };
    }
}
