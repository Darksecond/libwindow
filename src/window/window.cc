#include <window/window.h>
#include <window/opengl.h>

#include <cstdlib>
#include <cassert>
#include <cstdio> //TODO replace with libcore logger

static GLFWwindow* _window = nullptr;

void window::init()
{
    if(!glfwInit())
    {
        ::exit(EXIT_FAILURE);
    }
}

void window::exit()
{
    glfwTerminate();
}

void window::open(const int width, const int height)
{
    assert(_window == nullptr);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    _window = glfwCreateWindow(width, height, "OpenGL Window", NULL, NULL);
    if(!_window)
    {
        glfwTerminate();
        ::exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(_window);

    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        glfwTerminate();
        ::exit(EXIT_FAILURE);
    }
    glGetError(); // Ignore first error from GLEW

    if(!GLEW_VERSION_3_3)
    {
        glfwTerminate();
        ::exit(EXIT_FAILURE);
    }

    //TODO use libcore logger
    printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
    printf("GLSL Version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    printf("Vendor: %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
}

void window::close()
{
    if(_window)
    {
        glfwDestroyWindow(_window);
    }
    _window = nullptr;
}

void window::set_title(const char* title) {
    assert(_window);
    glfwSetWindowTitle(_window, title);
}

void window::swap() {
    assert(_window);
    glfwSwapBuffers(_window);
    glfwPollEvents();
}

bool window::should_close() {
    assert(_window);
    return glfwWindowShouldClose(_window);
}
