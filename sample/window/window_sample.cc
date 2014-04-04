#include <window/window.h>
#include <window/keyboard.h>
#include <window/mouse.h>
#include <window/opengl.h>

#include <cstdio>
#include <cstring>

#include <core/util/event.h>
#include <core/memory/simple_arena.h>
#include <core/memory/system_allocator.h>
#include <core/logging/console_logger.h>

void key_callback(window::key key, bool pressed, bool repeat)
{
    printf("callback: K:%i(%s) P:%i R:%i\n",key,window::key_name(key),pressed,repeat);
}

int main() {
    core::system_allocator alloc;
    core::simple_arena<core::system_allocator> a(&alloc);
    core::console_logger l;
    core::log::set_logger(&l, 0);

    window::window win;
    window::keyboard kb;
    window::mouse ms;

    window::init();

    window::key_event::sink sink(&a, 2);

    window::button_event::sink sink2(&a, 1);
    window::cursor_event::sink sink3(&a, 1);
    window::scroll_event::sink sink4(&a, 1);

    win.bind(&sink);

    win.bind(&sink2);
    win.bind(&sink3);
    win.bind(&sink4);

    sink.add_listener<&key_callback>();
    sink.add_listener<window::keyboard, &window::keyboard::on_event>(&kb);

    sink2.add_listener<window::mouse, &window::mouse::on_event>(&ms);
    sink3.add_listener<window::mouse, &window::mouse::on_event>(&ms);
    sink4.add_listener<window::mouse, &window::mouse::on_event>(&ms);

    win.open(800, 600);
    while(!win.should_close() && !kb.is_pressed(window::key::escape)) {
        kb.begin_frame();
        ms.begin_frame();
        window::pump_events();

        if(kb.went_up(window::key::s))
            printf("went up\n");
        if(kb.went_down(window::key::s))
            printf("went down\n");
        if(kb.is_repeating(window::key::s))
            printf("repeating\n");
        if(kb.is_pressed(window::key::s))
            printf("pressed\n");

        char buf[512];
        sprintf(buf, "cur[%f, %f] dt[%f, %f] sc[%f, %f]",
                ms.cursor_position().x,
                ms.cursor_position().y,
                ms.cursor_delta().x,
                ms.cursor_delta().y,
                ms.scroll_delta().x,
                ms.scroll_delta().y
                );
        win.set_title(buf);

        win.swap();
    }
    win.close();
    window::exit();

    return 0;
}
