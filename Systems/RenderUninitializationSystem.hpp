#pragma once

#include "System.hpp"

namespace Quasar
{
     namespace Systems
    {
        class RenderUninitializationSystem : public System
        {
            public:
                RenderUninitializationSystem();
                void Initialize(EntityManager* entityManager) override;
                void Update(float deltaTime) override;
        };
    }
}
