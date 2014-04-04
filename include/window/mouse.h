#pragma once

#include <window/button.h>
#include <window/point.h>

    //typedef core::event<void (button,bool)> button_event;
    //typedef core::event<void (double,double)> cursor_event;
    //typedef core::event<void (float,float)> scroll_event;

namespace window
{
    class mouse
    {
    public:
        typedef point<double> delta;
        typedef point<double> position;
    private:
        struct button_state
        {
            bool pressed;
            bool went_up;
            bool went_down;
        };

        button_state _buttons[static_cast<int>(button::last)];


        delta _cur_delta;
        delta _scroll_delta;
        position _cur_pos;
    public:
        mouse();

        void on_event(button button, bool pressed); //Button
        void on_event(double xpos, double ypos); //Position
        void on_event(float xdelta, float ydelta); //Scroll

        void begin_frame();

        inline bool is_pressed(button button) const
        {
            return _buttons[static_cast<int>(button)].pressed;
        }

        inline bool went_up(button button) const
        {
            return _buttons[static_cast<int>(button)].went_up;
        }

        inline bool went_down(button button) const
        {
            return _buttons[static_cast<int>(button)].went_down;
        }

        inline const position& cursor_position() const
        {
            return _cur_pos;
        }

        inline const delta& cursor_delta() const
        {
            return _cur_delta;
        }

        inline const delta& scroll_delta() const
        {
            return _scroll_delta;
        }
    };
}
