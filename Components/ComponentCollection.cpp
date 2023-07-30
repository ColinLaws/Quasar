#include "ComponentCollection.hpp"

namespace Quasar::Components
{
    template <typename T>
    ComponentCollection<T>::ComponentCollection() {}

    template <typename T>
    ComponentCollection<T>::~ComponentCollection() {}

    template <typename T>
    T *ComponentCollection<T>::GetComponent(uint16_t gameObjectId)
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
    void ComponentCollection<T>::AddComponent(uint16_t gameObjectId, T component)
    {
        auto it = lookupTable.find(gameObjectId);

        if (it != lookupTable.end())
        {
            items[it->second] = component;
        }
        else
        {
            items.push_back(component);
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
