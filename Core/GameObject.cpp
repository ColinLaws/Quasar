#include "libdragon.h"

class GameObject {
    int64_t id = 0;
    bool enabled = false;

    GameObject() {
        id = 1;
    }

    
    void SetEnabled(bool state) 
    {
        enabled = state;
    }

    void Start()
    {

    }

    void Update()
    {

    }
    
    void Render()
    {

    }
};
