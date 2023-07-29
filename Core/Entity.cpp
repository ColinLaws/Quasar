#include "Entity.hpp"

Quasar::Core::Entity::Entity(int64_t id) : id(id) {
}
    
void Quasar::Core::Entity::SetEnabled(bool state) 
{
    enabled = state;
}
