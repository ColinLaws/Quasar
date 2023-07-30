#pragma once

#include "libdragon.h"
#include "Entity.hpp"
#include "../Components/IComponent.hpp"
#include "../Components/ComponentCollection.hpp"
#include "../Components/TransformComponent.hpp"
#include <vector>

using Quasar::Components::IComponent;
using Quasar::Components::ComponentCollection;
using Quasar::Components::TransformComponent;
using std::vector;

namespace Quasar::Core
{
    class EntityManager
    {
        public: 
            EntityManager();
            uint16_t CreateEntity();
            void DeleteEntity(uint16_t id);
            void AddComponent(uint16_t entityId, IComponent* component);

        private:
            ComponentCollection<TransformComponent> transformComponents;
            vector<Entity> entities;
            uint16_t nextId = 0;
    };
}
