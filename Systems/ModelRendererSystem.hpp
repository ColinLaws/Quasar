#pragma once

#include "System.hpp"

namespace Quasar
{
    namespace System
    {
        class ModelRendererSystem : public System
        {
            public:
                ModelRendererSystem();
                void Initialize(EntityManager* entityManager) override;
                void Update(float deltaTime) override;
        };
    }
}
