#pragma once
#include "IComponent.hpp"

namespace Quasar::Core::Components {
    class Camera : public IComponent
    {
        public:
            Camera();

        public:
            int fov = 90;
    };
}
