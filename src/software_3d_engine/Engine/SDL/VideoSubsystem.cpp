//
// Created by kyle on 10/30/20.
//

#include <SDL2/SDL.h>

#include "../Streams/StringBuilder.hpp"
#include "VideoSubsystem.hpp"
Engine::SDL::VideoSubsystem::VideoSubsystem(
    const Engine::SDL::Context &context,
    gsl::not_null<Engine::Error *> e) noexcept
    : m_isActive(true)
{
    if (!context.IsActive())
    {
        *e = Error(
            std::make_error_code(std::errc::invalid_argument),
            "Invalid SDL context was passed to VideoSubsystem constructor");
        m_isActive = false;
    }
    else if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0)
    {
        *e = Error(std::make_error_code(std::errc::state_not_recoverable),
                   Streams::StringBuilder()
                       .Push("SDL video subsystem failed to initialize: ")
                       .Push(SDL_GetError())
                       .Build());
        m_isActive = false;
    }
}
Engine::SDL::VideoSubsystem::~VideoSubsystem() noexcept
{
    if (m_isActive)
    {
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }
}
Engine::SDL::VideoSubsystem::VideoSubsystem(
    Engine::SDL::VideoSubsystem &&other) noexcept
    : m_isActive(other.m_isActive)
{
    other.m_isActive = false;
}
Engine::SDL::VideoSubsystem &Engine::SDL::VideoSubsystem::operator=(
    Engine::SDL::VideoSubsystem &&other) noexcept
{
    if (&other != this)
    {
        m_isActive = other.m_isActive;
        other.m_isActive = false;
    }
    return *this;
}
bool Engine::SDL::VideoSubsystem::IsActive() const noexcept
{
    return m_isActive;
}
