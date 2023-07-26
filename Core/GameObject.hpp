#include "libdragon.h"

class GameObject {
    
public:
    GameObject();
    ~GameObject();

    void SetEnabled(bool enabled);

    void Start();
    void Update();
    void Render();

public:
    int64_t id = 0;

private:
    bool enabled = false;
};
