#include "first_app.hpp"

namespace lve
{
    void FirstApp::run()
    {
        while (!lvewindow.shouldClose())
        {
            glfwPollEvents();
        }
    }
} // namespace lve