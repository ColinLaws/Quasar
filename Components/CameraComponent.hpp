#pragma once
#include "IComponent.hpp"

namespace Quasar::Components {
    class Camera : public IComponent
    {
        public:
            Camera();
            std::string GetType() override;

        public:
            int fov = 90;
    };
}
