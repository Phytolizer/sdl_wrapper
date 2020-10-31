//
// Created by kyle on 10/30/20.
//

#include <SDL2/SDL.h>

#include "context.hpp"

#include "../Streams/StringBuilder.hpp"

Engine::SDL::Context::Context(gsl::not_null<Engine::Error *> e) noexcept
    : m_isActive(true)
{
    if (SDL_Init(0) != 0)
    {
        *e = Error(std::make_error_code(std::errc::state_not_recoverable),
                   Streams::StringBuilder()
                       .Push("SDL failed to initialize: ")
                       .Push(SDL_GetError())
                       .Build());
        m_isActive = false;
    }
}

Engine::SDL::Context::~Context() noexcept
{
    if (m_isActive)
    {
        SDL_Quit();
    }
}
Engine::SDL::Context::Context(Engine::SDL::Context &&other) noexcept
    : m_isActive(other.m_isActive)
{
    other.m_isActive = false;
}
Engine::SDL::Context &Engine::SDL::Context::operator=(
    Engine::SDL::Context &&other) noexcept
{
    if (&other != this)
    {
        m_isActive = other.m_isActive;
        other.m_isActive = false;
    }
    return *this;
}
bool Engine::SDL::Context::IsActive() const noexcept
{
    return m_isActive;
}
