#pragma once

#include "libdragon.h"

#include <vector>
#include <unordered_map>
#include <memory>
#include "Entity.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/ComponentCollection.hpp"

using std::unordered_map;
using std::vector;
using std::shared_ptr;
using Quasar::Core::Components::ComponentCollection;
using Quasar::Core::Components::TransformComponent;
using Quasar::Core::Entity;

namespace Quasar::Core 
{
    class Scene
    {
        public: 
            Scene();

        private:
            ComponentCollection<TransformComponent> transformComponents;
            vector<Entity> entities;
    };
}

