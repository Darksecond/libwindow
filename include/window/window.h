#pragma once

#include <window/key.h>
#include <window/button.h>
#include <core/util/event.h>

struct GLFWwindow;

namespace window
{
    void init();
    void exit();

    /**
     * Starts the current frame, performs the built-in message pump
     * Input event callbacks will be called during this call.
     */
    void begin_frame();

    /**
     * Key event, a key has been pressed, released or repeated.
     * key is the key on which an event occured
     * bool is the state (pressed or released)
     * bool is the repeat state (repeated or not)
     */
    typedef core::event<void (key,bool,bool)> key_event;

    /**
     * mouse scroll event
     * float is x-axis
     * float is y-axis
     */
    typedef core::event<void (float,float)> scroll_event;

    /**
     * mouse cursor move event
     * double is x-position
     * double is y-position
     */
    typedef core::event<void (double,double)> cursor_event;

    /**
     * Mouse button event
     * button is the button pressed or released
     * bool is the state (pressed or released)
     */
    typedef core::event<void (button,bool)> button_event;

    class window
    {
        GLFWwindow* _window;
    public:
        window();

        void open(const int width, const int height);
        void close();

        bool should_close();

        /**
         * This can only be called *after* open() has been called.
         */
        void set_title(const char* title);

        /**
         * Ends the current frame, swaps the display buffers.
         */
        void end_frame();

        void bind(key_event::sink* sink);
        void bind(scroll_event::sink* sink);
        void bind(cursor_event::sink* sink);
        void bind(button_event::sink* sink);
    private:
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
        static void cursor_callback(GLFWwindow* window, double xpos, double ypos);
        static void button_callback(GLFWwindow* window, int button, int action, int mods);

        key_event _key_event;
        scroll_event _scroll_event;
        cursor_event _cursor_event;
        button_event _button_event;
    };
}
