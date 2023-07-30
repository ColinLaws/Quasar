#pragma once

#include <vector>
#include <unordered_map>

namespace Quasar::Components
{
    template <typename T>
    class ComponentCollection 
    {
        static_assert(std::is_base_of<IComponent, T>::value, "T must be a subclass of IComponent");

        public:
            ComponentCollection();
            ~ComponentCollection();

            T* GetComponent(uint16_t gameObjectId);
            bool HasComponent(uint16_t gameObjectId);
            void AddComponent(uint16_t gameObjectId, T component);
            void RemoveComponent(uint16_t gameObjectId);

            void Clear();

        private:
            std::vector<T> items;
            std::unordered_map<uint16_t, size_t> lookupTable;
    };
}
