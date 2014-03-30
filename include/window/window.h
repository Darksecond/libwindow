#pragma once

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

    class window
    {
        GLFWwindow* _window;
    public:
        typedef core::event<void (int,int,int,int)> key_event;

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
    private:
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        key_event _key_event;
    };
}
