#pragma once

namespace window
{
    void init();
    void exit();
    void open(const int width, const int height);
    void close();
    bool should_close();
    void swap();
    void set_title(const char* title);
}
