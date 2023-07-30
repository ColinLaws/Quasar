#pragma once

#include <vector>
#include <unordered_map>

namespace Quasar::Core::Components
{
    template <typename T>
    class ComponentCollection 
    {
        static_assert(std::is_base_of<IComponent, T>::value, "T must be a subclass of IComponent");

        public:
            ComponentCollection();
            ~ComponentCollection();

            const T* GetComponent(uint32_t gameObjectId) const;
            bool HasComponent(uint32_t gameObjectId) const;
            void AddComponent(uint32_t gameObjectId, const T& component);
            void RemoveComponent(uint32_t gameObjectId);

            void Clear();

        private:
            std::vector<T> items;
            std::unordered_map<uint32_t, size_t> lookupTable;
    };
}
