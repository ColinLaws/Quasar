#pragma once

#include "System.hpp"

namespace Quasar
{
     namespace Systems
    {
        class InitializationSystem : public System
        {
            public:
                InitializationSystem();
                void Initialize(EntityManager* entityManager) override;
                void Update(float deltaTime) override;
        };
    }
}
