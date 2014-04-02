#include <window/button.h>
#include <window/opengl.h>

int window::button_to_glfw(button button)
{
    switch(button)
    {
        case button::left:   return GLFW_MOUSE_BUTTON_LEFT;
        case button::right:  return GLFW_MOUSE_BUTTON_RIGHT;
        case button::middle: return GLFW_MOUSE_BUTTON_MIDDLE;
        case button::four:   return GLFW_MOUSE_BUTTON_4;
        case button::five:   return GLFW_MOUSE_BUTTON_5;
        case button::six:    return GLFW_MOUSE_BUTTON_6;
        case button::seven:  return GLFW_MOUSE_BUTTON_7;
        case button::eight:  return GLFW_MOUSE_BUTTON_8;
        default:             return GLFW_MOUSE_BUTTON_LAST;
    }
}

window::button window::glfw_to_button(int button)
{
    switch(button)
    {
        case GLFW_MOUSE_BUTTON_LEFT:   return button::left;
        case GLFW_MOUSE_BUTTON_RIGHT:  return button::right;
        case GLFW_MOUSE_BUTTON_MIDDLE: return button::middle;
        case GLFW_MOUSE_BUTTON_4:      return button::four;
        case GLFW_MOUSE_BUTTON_5:      return button::five;
        case GLFW_MOUSE_BUTTON_6:      return button::six;
        case GLFW_MOUSE_BUTTON_7:      return button::seven;
        case GLFW_MOUSE_BUTTON_8:      return button::eight;
        default:                       return button::unknown;
    }
}

const char* window::button_name(button button)
{
    switch(button)
    {
        case button::left:   return "mouse left";
        case button::right:  return "mouse right";
        case button::middle: return "mouse middle";
        case button::four:   return "mouse 4";
        case button::five:   return "mouse 5";
        case button::six:    return "mouse 6";
        case button::seven:  return "mouse 7";
        case button::eight:  return "mouse 8";
        default:             return "mouse unknown";
    }
}
