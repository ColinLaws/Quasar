#pragma once

#include "libdragon.h"
#include "Entity.hpp"
#include "../Components/IComponent.hpp"
#include "../Components/ComponentCollection.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/ModelComponent.hpp"
#include <vector>
#include <typeindex>
#include <stdexcept>

using Quasar::Components::IComponent;
using Quasar::Components::ComponentCollection;
using Quasar::Components::TransformComponent;
using Quasar::Components::ModelComponent;

namespace Quasar
{
    namespace Core
    {
        class EntityManager
        {
            public:
                EntityManager();
                uint16_t CreateEntity();
                void DeleteEntity(uint16_t id);

                template <typename T>
                void RegisterComponentCollection(ComponentCollection<T>* collection)
                {
                    componentCollectionsMap.emplace(
                        std::type_index(typeid(T)), 
                        reinterpret_cast<ComponentCollection<IComponent>*>(collection)
                    );
                }

                template <typename T>
                void AddComponent(uint16_t entityId, T* component)
                {
                    auto it = componentCollectionsMap.find(std::type_index(typeid(T)));

                    if (it != componentCollectionsMap.end())
                    {
                        auto* collection = reinterpret_cast<ComponentCollection<T>*>(it->second);
                        collection->AddComponent(entityId, component);
                    }
                    else
                    {
                        throw std::runtime_error("Component type not registered!");
                    }
                }

                template <typename... ComponentTypes>
                std::vector<uint16_t> GetEntities()
                {
                    std::vector<uint16_t> matchingEntities;
    
                    for (auto& entity : entities)
                    {
                        if ((HasComponent<ComponentTypes>(entity.id) && ...))
                        {
                            matchingEntities.push_back(entity.id);
                        }
                    }
                    
                    return matchingEntities;
                }

                template <typename T>
                bool HasComponent(uint16_t entityId)
                {
                    auto it = componentCollectionsMap.find(std::type_index(typeid(T)));

                    if (it == componentCollectionsMap.end())
                    {
                        return false;
                    }
                    
                    auto* collection = reinterpret_cast<ComponentCollection<T>*>(it->second);
                    return collection->HasEntity(entityId);
                }

                template <typename T>
                T* GetComponent(uint16_t entityId)
                {
                    auto it = componentCollectionsMap.find(std::type_index(typeid(T)));

                    if (it == componentCollectionsMap.end())
                    {
                        throw std::runtime_error("Component type not registered!");
                    }
                    
                    auto* collection = reinterpret_cast<ComponentCollection<T>*>(it->second);
                    return collection->GetComponent(entityId);
                }

            private:
                std::unordered_map<std::type_index, ComponentCollection<IComponent>*> componentCollectionsMap;
                std::vector<Entity> entities;
                uint16_t nextId = 0;
        };
    }
}
