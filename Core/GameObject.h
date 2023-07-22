
class GameObject {
    
public:
    GameObject();
    ~GameObject();

    void SetEnabled(bool enabled);

    void Start();
    void Update();
    void Render();

private:
    bool enabled = false;
    

};
