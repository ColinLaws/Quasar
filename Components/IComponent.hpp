#pragma once

#include <string>

namespace Quasar::Components
{
    class IComponent 
    {
        virtual std::string GetType();
    };
}
