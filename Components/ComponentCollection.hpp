#pragma once

#include "libdragon.h"
#include "IComponent.hpp"
#include <vector>
#include <unordered_map>

namespace Quasar
{
    namespace Components
    {
            template <typename T>
            class ComponentCollection 
            {
                static_assert(std::is_base_of<IComponent, T>::value, "T must be a subclass of IComponent");

                public:
                    ComponentCollection<T>();
                    ~ComponentCollection();

                    T* GetComponent(uint16_t gameObjectId);
                    bool HasComponent(uint16_t gameObjectId);
                    void AddComponent(uint16_t gameObjectId, T* component);
                    void RemoveComponent(uint16_t gameObjectId);

                    void Clear();

                public:
                    std::vector<T> items;

                private:
                    std::unordered_map<uint16_t, size_t> lookupTable;
            };

            template <typename T>
            ComponentCollection<T>::ComponentCollection() {}

            template <typename T>
            ComponentCollection<T>::~ComponentCollection() {}

            template <typename T>
            T* ComponentCollection<T>::GetComponent(uint16_t gameObjectId)
            {
                auto it = lookupTable.find(gameObjectId);

                if (it != lookupTable.end())
                {
                    return &items[it->second];
                }

                return nullptr;
            }

            template <typename T>
            bool ComponentCollection<T>::HasComponent(uint16_t gameObjectId)
            {
                return lookupTable.find(gameObjectId) != lookupTable.end();
            }

            template <typename T>
            void ComponentCollection<T>::AddComponent(uint16_t gameObjectId, T* component)
            {
                auto it = lookupTable.find(gameObjectId);

                if (it != lookupTable.end())
                {
                    items[it->second] = *component;
                }
                else
                {
                    items.push_back(*component);
                    lookupTable[gameObjectId] = items.size() - 1;
                }
            }

            template <typename T>
            void ComponentCollection<T>::RemoveComponent(uint16_t gameObjectId)
            {
                // The ComponentCollection class could use some optimizations. 
                // When a component is removed, you're swapping the last component in
                // the list with the one you're removing and then popping the last 
                // element, which is a common trick to keep the vector compact. 
                // However, you are forgetting to update the lookupTable for the 
                // swapped component. As a result, after calling RemoveComponent, 
                // the lookupTable for the last element in items (before the pop) 
                // will still point to its old location, which is now invalid. 
                // This bug could lead to unexpected behavior or crashes.

                auto it = lookupTable.find(gameObjectId);

                if (it != lookupTable.end())
                {
                    size_t index = it->second;
                    items[index] = items.back();
                    items.pop_back();
                    lookupTable.erase(it);
                }
            }

            template <typename T>
            void ComponentCollection<T>::Clear()
            {
                items.clear();
                lookupTable.clear();
            }
    }
}
