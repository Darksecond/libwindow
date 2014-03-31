#include <window/window.h>
#include <window/keyboard.h>
#include <window/opengl.h>

#include <cstdio>

#include <core/util/event.h>
#include <core/memory/simple_arena.h>
#include <core/memory/system_allocator.h>
#include <core/logging/console_logger.h>

void key_callback(int key, int scancode, int action, int mods)
{
    printf("callback: K:%c(%i)(%s) A:%i\n", key, key, window::key_name(window::glfw_to_key(key)), action);
}


int main() {
    core::system_allocator alloc;
    core::simple_arena<core::system_allocator> a(&alloc);
    core::console_logger l;
    core::log::set_logger(&l, 0);

    window::window win;
    window::keyboard kb;

    window::init();

    window::key_event::sink sink(&a, 2);
    win.bind(&sink);
    sink.add_listener<&key_callback>();
    sink.add_listener<window::keyboard, &window::keyboard::on_event>(&kb);

    win.open(800, 600);
    while(!win.should_close() && !kb.is_pressed(window::key::escape)) {
        kb.begin_frame();
        window::begin_frame();

        if(kb.went_up(window::key::s))
            printf("went up\n");
        if(kb.went_down(window::key::s))
            printf("went down\n");
        if(kb.is_repeating(window::key::s))
            printf("repeating\n");
        if(kb.is_pressed(window::key::s))
            printf("pressed\n");

        win.end_frame();
    }
    win.close();
    window::exit();

    return 0;
}
