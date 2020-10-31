//
// Created by kyle on 10/30/20.
//

#pragma once

#include "../Error.hpp"
#include "context.hpp"
#include <gsl/gsl>
namespace Engine::SDL
{

class VideoSubsystem final
{
  private:
    bool m_isActive;

  public:
    explicit VideoSubsystem(const Context &context, gsl::not_null<Error *>e) noexcept;
    ~VideoSubsystem() noexcept;
    VideoSubsystem(const VideoSubsystem &) = delete;
    VideoSubsystem(VideoSubsystem &&other) noexcept;
    VideoSubsystem &operator=(const VideoSubsystem &) = delete;
    VideoSubsystem &operator=(VideoSubsystem &&other) noexcept;
    [[nodiscard]] bool IsActive() const noexcept;
};

} // namespace Engine::SDL
