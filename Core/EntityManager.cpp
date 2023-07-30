#include "EntityManager.hpp"
#include <algorithm>

using std::remove_if;

namespace Quasar
{
    namespace Core
    {
        EntityManager::EntityManager()
        {
        }

        uint16_t EntityManager::CreateEntity()
        {
            Entity entity = Entity(nextId++);

            entities.push_back(entity);

            return entity.id;
        }

        void EntityManager::DeleteEntity(uint16_t id)
        {
            transformComponents.RemoveComponent(id);

            entities.erase(remove_if(entities.begin(), entities.end(), [id](const Entity& entity) {
                return entity.id == id;
            }), entities.end());
        }

        void EntityManager::AddComponent(uint16_t entityId, IComponent* component)
        {
            TransformComponent* transformComponent = static_cast<TransformComponent*>(component);

            if (transformComponent != nullptr)
            {
                transformComponents.AddComponent(entityId, transformComponent);
            }
        }
    }
}
