#pragma once

#include "model64.h"
#include "IComponent.hpp"

namespace Quasar 
{
    namespace Components
    {
        class ModelComponent : public IComponent
        {
            public:
                ModelComponent(model64_t* model);
                std::string GetType() override;

            private:
                model64_t* model;
        };
    }
}
