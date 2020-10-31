//
// Created by kyle on 10/30/20.
//

#include "Window.hpp"
#include "../Streams/StringBuilder.hpp"
Engine::SDL::Window::Window(const Engine::SDL::VideoSubsystem &videoSubsystem,
                            gsl::not_null<Error *> e, std::string_view title,
                            Engine::Primitives::position position,
                            Engine::Primitives::dimension dimensions,
                            Uint32 flags)
{
    if (!videoSubsystem.IsActive())
    {
        *e = Error(
            std::make_error_code(std::errc::invalid_argument),
            "Invalid SDL video subsystem was passed to Window constructor");
        m_handle = nullptr;
    }
    else
    {
        m_handle = SDL_CreateWindow(title.data(), position.x, position.y,
                                    dimensions.w, dimensions.h, flags);
        if (m_handle == nullptr)
        {
            *e = Error(std::make_error_code(std::errc::state_not_recoverable),
                       Streams::StringBuilder()
                           .Push("SDL window creation failed: ")
                           .Push(SDL_GetError())
                           .Build());
        }
    }
}
Engine::SDL::Window::Window(const Engine::SDL::VideoSubsystem &videoSubsystem,
                            gsl::not_null<Engine::Error *> e,
                            std::string_view title,
                            Engine::Primitives::position position,
                            Engine::Primitives::dimension dimensions) noexcept
    : Window(videoSubsystem, e, title, position, dimensions, 0)
{
}
Engine::SDL::Window::~Window() noexcept
{
    if (m_handle != nullptr)
    {
        SDL_DestroyWindow(m_handle);
    }
}
Engine::SDL::Window::Window(Engine::SDL::Window &&other) noexcept
    : m_handle(other.m_handle)
{
    other.m_handle = nullptr;
}
Engine::SDL::Window &Engine::SDL::Window::operator=(
    Engine::SDL::Window &&other) noexcept
{
    if (&other != this)
    {
        if (m_handle != nullptr)
        {
            SDL_DestroyWindow(m_handle);
        }
        m_handle = other.m_handle;
        other.m_handle = nullptr;
    }
    return *this;
}
bool Engine::SDL::Window::IsValid() const noexcept
{
    return m_handle != nullptr;
}
