//
// Created by kyle on 10/30/20.
//

#include "WindowBuilder.hpp"
Engine::SDL::WindowBuilder::WindowBuilder(
    std::string_view title, Engine::Primitives::position position,
    Primitives::dimension dimensions) noexcept
    : m_title(title), m_position(position), m_dimension(dimensions), m_flags(0)
{
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::AllowHighDpi() noexcept
{
    m_flags |= SDL_WINDOW_ALLOW_HIGHDPI;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::AlwaysOnTop() noexcept
{
    m_flags |= SDL_WINDOW_ALWAYS_ON_TOP;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::Borderless() noexcept
{
    m_flags |= SDL_WINDOW_BORDERLESS;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::Foreign() noexcept
{
    m_flags |= SDL_WINDOW_FOREIGN;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::Fullscreen() noexcept
{
    m_flags |= SDL_WINDOW_FULLSCREEN;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::
    FullscreenDesktop() noexcept
{
    m_flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::Hidden() noexcept
{
    m_flags |= SDL_WINDOW_HIDDEN;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::InputFocus() noexcept
{
    m_flags |= SDL_WINDOW_INPUT_FOCUS;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::InputGrabbed() noexcept
{
    m_flags |= SDL_WINDOW_INPUT_GRABBED;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::Maximized() noexcept
{
    m_flags |= SDL_WINDOW_MAXIMIZED;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::Minimized() noexcept
{
    m_flags |= SDL_WINDOW_MINIMIZED;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::MouseCapture() noexcept
{
    m_flags |= SDL_WINDOW_MOUSE_CAPTURE;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::MouseFocus() noexcept
{
    m_flags |= SDL_WINDOW_MOUSE_FOCUS;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::OpenGL() noexcept
{
    m_flags |= SDL_WINDOW_OPENGL;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::PopupMenu() noexcept
{
    m_flags |= SDL_WINDOW_POPUP_MENU;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::Resizable() noexcept
{
    m_flags |= SDL_WINDOW_RESIZABLE;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::Shown() noexcept
{
    m_flags |= SDL_WINDOW_SHOWN;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::SkipTaskbar() noexcept
{
    m_flags |= SDL_WINDOW_SKIP_TASKBAR;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::Tooltip() noexcept
{
    m_flags |= SDL_WINDOW_TOOLTIP;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::Utility() noexcept
{
    m_flags |= SDL_WINDOW_UTILITY;
    return *this;
}
Engine::SDL::WindowBuilder &Engine::SDL::WindowBuilder::Vulkan() noexcept
{
    m_flags |= SDL_WINDOW_VULKAN;
    return *this;
}
Engine::SDL::Window Engine::SDL::WindowBuilder::Build(
    const VideoSubsystem &videoSubsystem, gsl::not_null<Error *> e) noexcept
{
    return Engine::SDL::Window(videoSubsystem, e, m_title, m_position,
                               m_dimension, m_flags);
}
