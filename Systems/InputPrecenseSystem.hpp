#pragma once

#include "System.hpp"

namespace Quasar
{
     namespace Systems
    {
        class InputPresenceSystem : public System
        {
            public:
                InputPresenceSystem();
                void Initialize(EntityManager* entityManager) override;
                void Update(float deltaTime) override;
        };
    }
}
