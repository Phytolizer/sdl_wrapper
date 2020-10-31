//
// Created by kyle on 10/30/20.
//

#pragma once

#include "Typedefs.hpp"
#include <SDL2/SDL_video.h>

namespace Engine::Primitives
{

struct position
{
    PositionType x;
    PositionType y;
};

constexpr position POSITION_CENTERED{.x = SDL_WINDOWPOS_CENTERED,
                                     .y = SDL_WINDOWPOS_CENTERED};
constexpr position POSITION_UNDEFINED{.x = SDL_WINDOWPOS_UNDEFINED,
                                      .y = SDL_WINDOWPOS_UNDEFINED};

} // namespace Engine::Primitives
