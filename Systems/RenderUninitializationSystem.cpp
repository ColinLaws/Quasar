#include "GL/gl.h"
#include "GL/glu.h"
#include <GL/gl_integration.h>
#include "RenderUninitializationSystem.hpp"
#include "../Components/ModelComponent.hpp"

using Quasar::Components::ModelComponent;

namespace Quasar
{
     namespace Systems
    {
        RenderUninitializationSystem::RenderUninitializationSystem()
        {
        }

        void RenderUninitializationSystem::Initialize(EntityManager* entityManager)
        {

        }

        void RenderUninitializationSystem::Update(float deltaTime)
        {
            glDisable(GL_BLEND);
            gl_context_end();
            glFlush();
            rdpq_detach_show();
        }
    }
}
