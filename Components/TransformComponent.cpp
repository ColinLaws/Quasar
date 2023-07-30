#include "TransformComponent.hpp"

Quasar::Components::TransformComponent::TransformComponent()
{

}

Quasar::Components::TransformComponent::TransformComponent(
    float posX, float posY, float posZ,
    float rotX, float rotY, float rotZ,
    float scaX, float scaY, float scaZ
) 
{
    char x = 0x0;
    char y = 0x1;
    char z = 0x2;

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

std::string Quasar::Components::TransformComponent::GetType()
{
    return "TransformComponent";
}
