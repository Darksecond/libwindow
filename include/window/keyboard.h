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

        key_state _keys[static_cast<int>(key::last)];
    public:
        keyboard();

        void on_event(key key, bool pressed, bool repeat);

        /**
         * Clears certain internal buffers.
         * This should be called before window::start_frame().
         */
        void begin_frame();

        inline bool is_pressed(key key) const
        {
            return _keys[static_cast<int>(key)].pressed;
        }

        inline bool went_up(key key) const
        {
            return _keys[static_cast<int>(key)].went_up;
        }

        inline bool went_down(key key) const
        {
            return _keys[static_cast<int>(key)].went_down;
        }

        inline bool is_repeating(key key) const
        {
            return _keys[static_cast<int>(key)].repeat;
        }

        /**
         * \returns the key that was pressed, returns key::unknown if none was pressed
         */
        key any_is_pressed() const;

        key any_went_up() const;
        key any_went_down() const;
        key any_is_repeating() const;
    };
}
