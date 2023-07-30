#pragma once

#include "../Core/EntityManager.hpp"

using Quasar::Core::EntityManager;

namespace Quasar::System
{
    class System
    {
        public:
            System(EntityManager* entityManager);
            void Update(float deltaTime);

        protected:
            EntityManager* entityManager;
    };
}
