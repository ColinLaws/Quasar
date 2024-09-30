#pragma once

#include "System.hpp"

namespace Quasar
{
     namespace Systems
    {
        class RenderInitializationSystem : public System
        {
            public:
                RenderInitializationSystem();
                void Initialize(EntityManager* entityManager) override;
                void Update(float deltaTime) override;

            private:
                surface_t zbuffer;
        };
    }
}
