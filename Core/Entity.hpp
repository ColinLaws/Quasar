extern "C" {
    #include "libdragon.h"
}

#include "TransformComponent.hpp"

namespace Quasar::Core {
    class Entity {
        public:
            Entity(int64_t id);

            void SetEnabled(bool enabled);

        public:
            int64_t id = 0;

        private:
            bool enabled = true;
    };
}
