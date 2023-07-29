#include "Entity.hpp"
#include "Components/TransformComponent.hpp"
#include <vector>
#include <unordered_map>
#include <memory>

using std::unordered_map;
using std::vector;
using std::shared_ptr;

namespace Quasar::Core 
{
    class Scene
    {
        public: 
            Scene();

        private:
            vector<Quasar::Core::Entity> entities;
            vector<std::shared_ptr<Quasar::Core::Components::TransformComponent>> transformComponents;

            unordered_map<int64_t, std::shared_ptr<Quasar::Core::Components::TransformComponent>> entityIdToTransformComponentIndexMap;
    };
}

