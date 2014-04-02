#pragma once

namespace window
{
    enum class button : int
    {
        unknown = -1,
        left = 0,
        right,
        middle,
        four,
        five,
        six,
        seven,
        eight,
        last,
    };


    int button_to_glfw(button button);
    button glfw_to_button(int button);
    const char* button_name(button button);
}
