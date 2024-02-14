#pragma once
#include "IComponent.hpp"

namespace Quasar 
{
    namespace Components
    {
        class Camera : public IComponent
        {
            public:
                Camera();

            public:
                int fov = 90;
        };
    }
}
