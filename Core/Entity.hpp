#pragma once

#include "libdragon.h"

namespace Quasar::Core {
    class Entity {
        public:
            Entity(uint16_t id);

        public:
            uint16_t id = 0;
    };
}
