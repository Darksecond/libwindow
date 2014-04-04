#include <window/mouse.h>

#include <cstring>

window::mouse::mouse()
{
    memset(_buttons, 0, sizeof(_buttons));
}

void window::mouse::begin_frame()
{
    for(int i=0;i<static_cast<int>(button::last);++i)
    {
        _buttons[i].went_up = false;
        _buttons[i].went_down = false;
    }

    _cur_delta.zero();
    _scroll_delta.zero();
}

void window::mouse::on_event(button b, bool pressed)
{
    if(b == button::unknown) return; //safety check

    button_state& state = _buttons[static_cast<int>(b)];

    if(pressed && !state.pressed)
        state.went_down = true;
    else if(!pressed && state.pressed)
        state.went_up = true;
    state.pressed = pressed;
}

void window::mouse::on_event(double xpos, double ypos)
{
    position pos(xpos, ypos);

    _cur_delta = _cur_pos - pos;
    _cur_pos = pos;
}

void window::mouse::on_event(float xdelta, float ydelta)
{
    delta dt(xdelta, ydelta);

    _scroll_delta = dt;
}
