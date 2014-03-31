#include <window/window.h>
#include <window/opengl.h>

#include <core/logging/log.h>

#include <cstdlib>
#include <cassert>

window::window::window() : _window(nullptr)
{
}

void window::window::key_callback(GLFWwindow* window, int glfw_key, int scancode, int action, int mods)
{
    window::window* win = reinterpret_cast<window::window*>(glfwGetWindowUserPointer(window));
    key k = glfw_to_key(glfw_key);
    if(win->_key_event.is_bound())
        win->_key_event.signal(k, (action != GLFW_RELEASE), (action == GLFW_REPEAT));
}

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

void window::begin_frame()
{
    glfwPollEvents();
}

void window::window::bind(key_event::sink* sink)
{
    _key_event.bind(sink);
}

void window::window::end_frame()
{
    assert(_window);
    glfwSwapBuffers(_window);
}

void window::window::set_title(const char* title)
{
    assert(_window);
    glfwSetWindowTitle(_window, title);
}

bool window::window::should_close()
{
    assert(_window);
    return glfwWindowShouldClose(_window);
}

void window::window::close()
{
    if(_window)
    {
        glfwDestroyWindow(_window);
    }
    _window = nullptr;
}

void window::window::open(const int width, const int height)
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

    glfwSetWindowUserPointer(_window, this);
    glfwSetKeyCallback(_window, &key_callback);

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

    CORE_LINFO("system", "OpenGL Version: %s", glGetString(GL_VERSION));
    CORE_LINFO("system", "GLSL Version: %s", glGetString(GL_SHADING_LANGUAGE_VERSION));
    CORE_LINFO("system", "Vendor: %s", glGetString(GL_VENDOR));
    CORE_LINFO("system", "Renderer: %s", glGetString(GL_RENDERER));
}
