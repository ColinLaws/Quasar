#include "ModelComponent.hpp"

namespace Quasar
{
    namespace Components
    {
        ModelComponent::ModelComponent(model64_t* model) : model(model)
        {
            
        }

        std::string ModelComponent::GetType()
        {
            return "ModelComponent";
        }
    }
}
