#include "GL/GL.h"

#include "CameraComponent.hpp"

Quasar::Components::Camera::Camera()
{

}

// Quasar::Core::Camera::Render()
// {
//     glLoadIdentity();

//     // Apply the rotations
//     glRotatef(transform->rotation[0], 1.0f, 0.0f, 0.0f); // rotation around X-axis
//     glRotatef(transform->rotation[1], 0.0f, 1.0f, 0.0f); // rotation around Y-axis
//     glRotatef(transform->rotation[2], 0.0f, 0.0f, 1.0f); // rotation around Z-axis

//     // Translate to the camera position
//     glTranslatef(-transform->position[0], -transform->position[1], -transform->position[2]);
// }

std::string Quasar::Components::Camera::GetType()
{
    return "CameraComponent";
}
