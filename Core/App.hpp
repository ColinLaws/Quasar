#pragma once

#include "libdragon.h"
#include "../Systems/SystemsPipeline.hpp"

using Quasar::Systems::SystemsPipeline;

namespace Quasar
{
    namespace Core
    {
        class App
        {
            public:
                App();
                void Update();

            private:
                void Initialize();
                void SetupSystemsPipeline();

            private:
                SystemsPipeline* systemsPipeline;
                EntityManager* entityManager;
        };
    }
}
