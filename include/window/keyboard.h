#pragma once

namespace window
{
    class keyboard
    {
    public:
        enum class key : int
        {
            unknown = -1,
            space = 0,
            apostrophe,
            comma,
            minus,
            period,
            slash,
            zero,
            one,
            two,
            three,
            four,
            five,
            six,
            seven,
            eight,
            nine,
            semicolon,
            equal,
            a,
            b,
            c,
            d,
            e,
            f,
            g,
            h,
            i,
            j,
            k,
            l,
            m,
            n,
            o,
            p,
            q,
            r,
            s,
            t,
            u,
            v,
            w,
            x,
            y,
            z,
            left_bracket,
            backslash,
            right_bracket,
            grave_accent,
            world_1,
            world_2,
            escape,
            enter,
            tab,
            backspace,
            insert,
            del,
            right,
            left,
            down,
            up,
            page_up,
            page_down,
            home,
            end,
            caps_lock,
            scroll_lock,
            num_lock,
            print_screen,
            pause,
            F1,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7,
            F8,
            F9,
            F10,
            F11,
            F12,
            F13,
            F14,
            F15,
            F16,
            F17,
            F18,
            F19,
            F20,
            F21,
            F22,
            F23,
            F24,
            F25,
            kp_0,
            kp_1,
            kp_2,
            kp_3,
            kp_4,
            kp_5,
            kp_6,
            kp_7,
            kp_8,
            kp_9,
            kp_decimal,
            kp_divide,
            kp_multiply,
            kp_subtract,
            kp_add,
            kp_enter,
            kp_equal,
            left_shift,
            left_control,
            left_alt,
            left_super,
            right_shift,
            right_control,
            right_alt,
            right_super,
            menu,
            last, /// Not an actual key, but it is used to allocate arrays.
        };
    private:
        /**
         * Translate between libwindow keys and GLFW keys.
         * TODO Make this a static only function perhaps, so we can remove it from this header entirely.
         */

        int key_to_glfw(key key);
        key glfw_to_key(int key);

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