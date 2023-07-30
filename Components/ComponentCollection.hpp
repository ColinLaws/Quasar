#pragma once

#include "libdragon.h"
#include "IComponent.hpp"
#include <vector>
#include <unordered_map>

namespace Quasar::Components
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

        private:
            std::vector<T> items;
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
