#include "TransformComponent.hpp"

namespace Quasar
{
    namespace Components
    {
        TransformComponent::TransformComponent()
        {
            
        }

        TransformComponent::TransformComponent(
            float posX, float posY, float posZ,
            float rotX, float rotY, float rotZ,
            float scaX, float scaY, float scaZ
        ) 
        {
            int x = 0x0;
            int y = 0x1;
            int z = 0x2;

            position[x] = posX;
            position[y] = posY;
            position[z] = posZ;

            rotation[x] = rotX;
            rotation[y] = rotY;
            rotation[z] = rotZ;

            scale[x] = scaX;
            scale[y] = scaY;
            scale[z] = scaZ;
        }
    }
}
