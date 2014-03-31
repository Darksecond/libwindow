#include <window/keyboard.h>
#include <window/opengl.h>

#include <cstring>

void window::keyboard::on_event(key k, bool pressed, bool repeat)
{
    if(k == key::unknown) return; //safety check

    key_state& state = _keys[static_cast<int>(k)];

    if(pressed && !state.pressed)
        state.went_down = true;
    else if(!pressed && state.pressed)
        state.went_up = true;
    state.repeat = repeat;
    state.pressed = pressed;
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
