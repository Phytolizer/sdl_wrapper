//
// Created by kyle on 10/30/20.
//

#include <SDL2/SDL.h>

#include "Application.hpp"
#include "SDL/VideoSubsystem.hpp"
#include "SDL/context.hpp"

namespace Engine
{

void Application::Run()
{
    Error e;
    SDL::Context context(&e);
    if (e.code() != std::error_code{})
    {
        throw e;
    }
    SDL::VideoSubsystem video(context, &e);
}

} // namespace Engine
