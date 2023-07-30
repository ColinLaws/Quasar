#pragma once

#include "../Core/EntityManager.hpp"

using Quasar::Core::EntityManager;

namespace Quasar
{
     namespace Systems
    {
        class System
        {
            public:
                virtual void Initialize(EntityManager* entityManager) = 0;
                virtual void Update(float deltaTime);

            protected:
                EntityManager* entityManager;
        };
    }
}
