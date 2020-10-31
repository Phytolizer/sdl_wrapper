//
// Created by kyle on 10/30/20.
//

#pragma once

#include "../Error.hpp"
#include "../Primitives/Dimension.hpp"
#include "../Primitives/Position.hpp"
#include "Window.hpp"
#include <gsl/gsl>
#include <string_view>

namespace Engine::SDL
{

class WindowBuilder
{
  private:
    std::string_view m_title;
    Primitives::position m_position;
    Primitives::dimension m_dimension;
    Uint32 m_flags;

  public:
    WindowBuilder(std::string_view title, Primitives::position position,
                  Primitives::dimension dimensions) noexcept;
    /// create in high-DPI mode if supported
    WindowBuilder &AllowHighDpi() noexcept;
    /// always above other windows (X11 only)
    WindowBuilder &AlwaysOnTop() noexcept;
    /// no window decorations
    WindowBuilder &Borderless() noexcept;
    /// was not created by SDL
    WindowBuilder &Foreign() noexcept;
    /// fullscreen
    WindowBuilder &Fullscreen() noexcept;
    /// fullscreen, use current desktop resolution
    WindowBuilder &FullscreenDesktop() noexcept;
    /// not visible
    WindowBuilder &Hidden() noexcept;
    /// take input focus
    WindowBuilder &InputFocus() noexcept;
    /// take grabbed input focus
    WindowBuilder &InputGrabbed() noexcept;
    /// maximize window
    WindowBuilder &Maximized() noexcept;
    /// minimize window
    WindowBuilder &Minimized() noexcept;
    /// capture the mouse
    WindowBuilder &MouseCapture() noexcept;
    /// take mouse focus
    WindowBuilder &MouseFocus() noexcept;
    /// use OpenGL
    WindowBuilder &OpenGL() noexcept;
    /// window is a popup menu (X11 only)
    WindowBuilder &PopupMenu() noexcept;
    /// resizable
    WindowBuilder &Resizable() noexcept;
    /// visible
    WindowBuilder &Shown() noexcept;
    /// won't show up on the taskbar (X11 only)
    WindowBuilder &SkipTaskbar() noexcept;
    /// window is a tooltip (X11 only)
    WindowBuilder &Tooltip() noexcept;
    /// window is a utility window (X11 only)
    WindowBuilder &Utility() noexcept;
    /// use with a Vulkan instance
    WindowBuilder &Vulkan() noexcept;
    Window Build(const VideoSubsystem &videoSubsystem,
                 gsl::not_null<Error *> e) noexcept;
};

} // namespace Engine::SDL
