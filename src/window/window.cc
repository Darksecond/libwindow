#include <window/window.h>
#include <window/opengl.h>

#include <core/logging/log.h>

#include <cstdlib>
#include <cassert>

window::window::window() : _window(nullptr)
{
}

void window::window::button_callback(GLFWwindow* window, int glfw_button, int action, int mods)
{
    window::window* win = reinterpret_cast<window::window*>(glfwGetWindowUserPointer(window));
    assert(win);

    const button b = glfw_to_button(glfw_button);
    if(win->_button_event.is_bound())
        win->_button_event.signal(b, (action == GLFW_PRESS));
}

void window::window::cursor_callback(GLFWwindow* window, double xpos, double ypos)
{
    window::window* win = reinterpret_cast<window::window*>(glfwGetWindowUserPointer(window));
    assert(win);

    if(win->_cursor_event.is_bound())
        win->_cursor_event.signal(xpos, ypos);
}

void window::window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    window::window* win = reinterpret_cast<window::window*>(glfwGetWindowUserPointer(window));
    assert(win);

    if(win->_scroll_event.is_bound())
        win->_scroll_event.signal(xoffset, yoffset);
}

void window::window::key_callback(GLFWwindow* window, int glfw_key, int scancode, int action, int mods)
{
    window::window* win = reinterpret_cast<window::window*>(glfwGetWindowUserPointer(window));
    assert(win);

    const key k = glfw_to_key(glfw_key);
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

void window::window::bind(scroll_event::sink* sink)
{
    _scroll_event.bind(sink);
}

void window::window::bind(cursor_event::sink* sink)
{
    _cursor_event.bind(sink);
}

void window::window::bind(button_event::sink* sink)
{
    _button_event.bind(sink);
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
    glfwSetScrollCallback(_window, &scroll_callback);
    glfwSetCursorPosCallback(_window, &cursor_callback);
    glfwSetMouseButtonCallback(_window, &button_callback);

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
