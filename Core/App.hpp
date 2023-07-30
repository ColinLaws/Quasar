#pragma once

#include "libdragon.h"
#include "../Systems/SystemsPipeline.hpp";

namespace Quasar::Core
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
    };
}
