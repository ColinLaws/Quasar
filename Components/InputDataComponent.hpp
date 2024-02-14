#pragma once
#include "IComponent.hpp"
#include "libdragon.h"

namespace Quasar 
{
    namespace Components
    {
        class InputDataComponent : public IComponent
        {
            public:
                InputDataComponent();

            public:
                controller_data pressed;
        };
    }
}
