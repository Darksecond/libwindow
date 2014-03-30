#pragma once

#include <window/key.h>

namespace window
{
    class keyboard
    {
        struct key_state
        {
            bool pressed;
            bool went_up;
            bool went_down;
            bool repeat;
        };
        
        key_state _keys[(int)key::last];
    public:
        keyboard();

        void on_event(int,int,int,int);

        /**
         * Clears certain internal buffers.
         * This should be called before window::start_frame().
         */
        void begin_frame();

        inline bool is_pressed(key key)
        {
            return _keys[(int)key].pressed;
        }

        inline bool went_up(key key)
        {
            return _keys[(int)key].went_up;
        }

        inline bool went_down(key key)
        {
            return _keys[(int)key].went_down;
        }

        inline bool is_repeating(key key)
        {
            return _keys[(int)key].repeat;
        }
    };
}
