#ifndef CAMERA_H
#define CAMERA_H

static const int CAMERA_AXIS_X = 0;
static const int CAMERA_AXIS_Y = 1;
static const int CAMERA_AXIS_Z = 2;

typedef struct {
    float position[3]; // Position of the camera
    float rotation[3]; // Rotation angles around the x, y and z axes
} camera_t;

void camera_transform(const camera_t *camera)
{
    glLoadIdentity();

    // Apply the rotations
    glRotatef(camera->rotation[0], 1.0f, 0.0f, 0.0f); // rotation around X-axis
    glRotatef(camera->rotation[1], 0.0f, 1.0f, 0.0f); // rotation around Y-axis
    glRotatef(camera->rotation[2], 0.0f, 0.0f, 1.0f); // rotation around Z-axis

    // Translate to the camera position
    glTranslatef(-camera->position[0], -camera->position[1], -camera->position[2]);
}

#endif
