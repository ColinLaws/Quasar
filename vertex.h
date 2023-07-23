#ifndef VERTEX_H
#define VERTEX_H

#include <stdint.h>

class vertex_t {
public:
    float position[3];
    float texcoord[2];
    float normal[3];
    uint32_t color;

    vertex_t(float px, float py, float pz,
             float tx, float ty,
             float nx, float ny, float nz,
             uint32_t col) {
        position[0] = px;
        position[1] = py;
        position[2] = pz;

        texcoord[0] = tx;
        texcoord[1] = ty;

        normal[0] = nx;
        normal[1] = ny;
        normal[2] = nz;

        color = col;
    }
};

#endif // VERTEX_H  