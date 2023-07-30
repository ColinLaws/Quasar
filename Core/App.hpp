#pragma once

#include "libdragon.h"
#include "../Systems/SystemsPipeline.hpp";

using Quasar::System::SystemsPipeline;

namespace Quasar
{
    namespace Core
    {
        class App
        {
            public:
                App();

                void Update();
                void Render();

            private:
                void Initialize();
                void SetupSystemsPipeline();

            private:
                SystemsPipeline* systemsPipeline;
        };
    }
}
