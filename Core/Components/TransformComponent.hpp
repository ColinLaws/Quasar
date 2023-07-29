
namespace Quasar::Core::Components {
    class TransformComponent
    {
        public:
            TransformComponent();

            TransformComponent(
                float posX, float posY, float posZ,
                float rotX, float rotY, float rotZ,
                float scaX, float scaY, float scaZ
            );

        public:
            float position[3] = {0, 0, 0};
            float rotation[3] = {0, 0, 0};
            float scale[3] = {1, 1, 1};
    };
}
