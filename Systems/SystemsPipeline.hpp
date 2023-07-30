#pragma once

#include "System.hpp"
#include "../Core/EntityManager.hpp"

using std::vector;
using Quasar::System::System;
using Quasar::Core::EntityManager;

namespace Quasar::System
{
    class SystemsPipeline
    {
        public:
            SystemsPipeline();
            void Initialize();
      
            void Update(float deltaTime);

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
