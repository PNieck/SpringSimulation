#include <simulation/window.hpp>

#include <glad/glad.h>


unsigned int Window::instances_cnt = 0;


Window::Window(int width, int height, const std::string & name):
    window(CreateGFLWwindow(width, height, name)), controller(window, width, height)
{
    // Set window pointer to this class for all callback
    glfwSetWindowUserPointer(window, this);

    // Enable "vsync"
    glfwSwapInterval(1);
}


Window::~Window()
{
    glfwDestroyWindow(window);

    if (--instances_cnt == 0) {
        DeinitializeGLFW();
    }
}


GLFWwindow * Window::CreateGFLWwindow(int width, int height, const std::string &name)
{
    if (instances_cnt == 0) {
        InitializeGLFW();
    }

    GLFWwindow* window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    if (window == nullptr)
    {
        glfwTerminate();
        throw WindowCreationError("Cannot create window");
    }

    glfwMakeContextCurrent(window);
    InitializeGlad();

    // Set callbacks
    glfwSetFramebufferSizeCallback(window, SizeChangedCallback);
    glfwSetCursorPosCallback(window, MouseMoveCallback);
    glfwSetMouseButtonCallback(window, MouseButtonCallback);
    glfwSetScrollCallback(window, ScrollCallback);

    instances_cnt++;

    return window;
}


void Window::InitializeGLFW()
{
    if (glfwInit() != GLFW_TRUE) {
        throw WindowCreationError("Cannot initialize window module");
    }

    // Set OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}


void Window::DeinitializeGLFW()
{
    glfwTerminate();
}


void Window::InitializeGlad()
{
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        glfwTerminate();
        throw WindowCreationError("Cannot initialize Glad");
    }
}


void Window::RunMessageLoop()
{
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        controller.Render();

        glfwSwapBuffers(window);
    }
}


void Window::SizeChangedCallback(GLFWwindow * glfwWindow, int width, int height)
{
}


void Window::MouseMoveCallback(GLFWwindow * glfwWindow, double xpos, double ypos)
{
}


void Window::MouseButtonCallback(GLFWwindow * glfwWindow, int button, int action, int mods)
{

}


void Window::ScrollCallback(GLFWwindow * glfwWindow, double xoffset, double yoffset)
{
}
