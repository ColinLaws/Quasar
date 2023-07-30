#pragma once

#include "System.hpp"

namespace Quasar
{
     namespace Systems
    {
        class TransformSystem : public System
        {
            public:
                TransformSystem();
                void Initialize(EntityManager* entityManager) override;
                void Update(float deltaTime) override;
        };
    }
}
