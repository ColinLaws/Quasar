#include "GL/gl.h"
#include "libdragon.h"
#include "EntityManager.hpp"
#include <algorithm>
#include <exception>

using std::remove_if;
using std::exception;

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
            // Remove all components. It is safe to call RemoveComponent for an entity without that component.
            transformComponents.RemoveComponent(id);
            modelComponents.RemoveComponent(id);

            entities.erase(remove_if(entities.begin(), entities.end(), [id](const Entity& entity) {
                return entity.id == id;
            }), entities.end());
        }

        void EntityManager::AddComponent(uint16_t entityId, IComponent* component)
        {
            if (component->GetType() == "TransformComponent")
            {
                TransformComponent* transformComponent = static_cast<TransformComponent*>(component);

                if (transformComponent != nullptr)
                {
                    transformComponents.AddComponent(entityId, transformComponent);
                }
            }

            if (component->GetType() == "ModelComponent")
            {
                ModelComponent* modelComponent = static_cast<ModelComponent*>(component);

                if (modelComponent != nullptr)
                {
                    modelComponents.AddComponent(entityId, modelComponent);
                }
            }
        }
    }
}
