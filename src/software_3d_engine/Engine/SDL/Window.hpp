//
// Created by kyle on 10/30/20.
//

#pragma once

#include "../Primitives/Dimension.hpp"
#include "../Primitives/Position.hpp"
#include "VideoSubsystem.hpp"
#include <SDL2/SDL_video.h>
#include <gsl/gsl>
namespace Engine::SDL
{

class Window
{
  private:
    SDL_Window *m_handle;
    Window(const VideoSubsystem &videoSubsystem, gsl::not_null<Error *> e,
           std::string_view title, Primitives::position position,
           Primitives::dimension dimensions, Uint32 flags);
    friend class WindowBuilder;

  public:
    Window(const VideoSubsystem &videoSubsystem, gsl::not_null<Error *> e,
           std::string_view title, Primitives::position position,
           Primitives::dimension dimensions) noexcept;
    ~Window() noexcept;
    Window(const Window &) = delete;
    Window(Window &&other) noexcept;
    Window &operator=(const Window &) = delete;
    Window &operator=(Window &&other) noexcept;
    [[nodiscard]] bool IsValid() const noexcept;
};

} // namespace Engine::SDL
