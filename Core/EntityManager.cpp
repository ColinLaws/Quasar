#include "EntityManager.hpp"
#include <algorithm>

using std::remove_if;

Quasar::Core::EntityManager::EntityManager()
{

}

uint16_t Quasar::Core::EntityManager::CreateEntity()
{
    Entity entity = Entity(nextId++);

    entities.push_back(entity);

    return entity.id;
}

void Quasar::Core::EntityManager::DeleteEntity(uint16_t id)
{
    transformComponents.RemoveComponent(id);

    entities.erase(remove_if(entities.begin(), entities.end(), [id](const Entity& entity) {
        return entity.id == id;
    }), entities.end());
}

void Quasar::Core::EntityManager::AddComponent(uint16_t entityId, IComponent* component)
{
    TransformComponent* transformComponent = static_cast<TransformComponent*>(component);

    if (transformComponent != nullptr)
    {
        transformComponents.AddComponent(entityId, transformComponent);
    }
}
