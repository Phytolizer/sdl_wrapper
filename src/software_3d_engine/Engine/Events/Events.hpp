//
// Created by kyle on 10/30/20.
//

#pragma once

namespace Engine::Events
{

enum class event
{
    tick,
    render,
    window_closed,
    key_down,
    key_up,
    mouse_motion,
    mouse_button_press,
    mouse_button_release,
    mouse_wheel_motion,
};

} // namespace Engine::Events
