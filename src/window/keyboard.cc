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
    for(int i=0;i<static_cast<int>(key::last);++i)
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

window::key window::keyboard::any_is_pressed() const
{
    for(int i=0;i<static_cast<int>(key::last);++i)
    {
        if(_keys[i].pressed)
            return static_cast<key>(i);
    }
    return key::unknown;
}

window::key window::keyboard::any_went_up() const
{
    for(int i=0;i<static_cast<int>(key::last);++i)
    {
        if(_keys[i].went_up)
            return static_cast<key>(i);
    }
    return key::unknown;
}

window::key window::keyboard::any_went_down() const
{
    for(int i=0;i<static_cast<int>(key::last);++i)
    {
        if(_keys[i].went_down)
            return static_cast<key>(i);
    }
    return key::unknown;
}

window::key window::keyboard::any_is_repeating() const
{
    for(int i=0;i<static_cast<int>(key::last);++i)
    {
        if(_keys[i].repeat)
            return static_cast<key>(i);
    }
    return key::unknown;
}
