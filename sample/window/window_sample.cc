#include <window/window.h>

int main() {
    window::init();
    window::open(800,600);
    while(!window::should_close()) {
        window::swap();
    }
    window::close();
    window::exit();
    return 0;
}
