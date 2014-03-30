#include <window/keyboard.h>
#include <window/opengl.h>

#include <cstring>

void window::keyboard::on_event(int glfw_key, int, int action, int)
{
    key k = glfw_to_key(glfw_key);
    if(k == key::unknown) return; //safety check

    key_state& state = _keys[(int)k];

    if(action == GLFW_RELEASE)
    {
        if(state.pressed)
            state.went_up = true;
        state.pressed = false;
        state.repeat = false;
    }
    else if(action == GLFW_PRESS)
    {
        if(!state.pressed)
            state.went_down = true;
        state.pressed = true;
    }
    else if(action == GLFW_REPEAT)
    {
        state.repeat = true;
    }
}

void window::keyboard::begin_frame()
{
    for(int i=0;i<(int)key::last;++i)
    {
        _keys[i].went_up = false;
        _keys[i].went_down = false;
        _keys[i].repeat = false;
    }
}

window::keyboard::keyboard()
{
    memset(_keys, 0, sizeof(_keys));
}
