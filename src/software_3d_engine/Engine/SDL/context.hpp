//
// Created by kyle on 10/30/20.
//

#pragma once

#include "../Error.hpp"
#include <gsl/gsl>

namespace Engine::SDL
{

class Context final
{
  private:
    bool m_isActive;

  public:
    explicit Context(gsl::not_null<Error *>e) noexcept;
    ~Context() noexcept;
    Context(const Context &) = delete;
    Context(Context &&other) noexcept;
    Context &operator=(const Context &) = delete;
    Context &operator=(Context &&other) noexcept;
    [[nodiscard]] bool IsActive() const noexcept;
};

} // namespace Engine::SDL
