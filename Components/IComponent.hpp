#pragma once

#include <string>

namespace Quasar::Components
{
    class IComponent 
    {
        public:
            virtual ~IComponent(); 
            virtual std::string GetType();
    };
}
