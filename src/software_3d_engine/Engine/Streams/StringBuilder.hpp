//
// Created by kyle on 10/30/20.
//

#pragma once

#include "OutputStream.hpp"
#include <sstream>
namespace Engine::Streams
{

class StringBuilder
{
    std::stringstream m_ss;
    OutputStream m_underlying;

  public:
    StringBuilder() noexcept;

    template <OutputStreamable T>
    StringBuilder &Push(T arg) noexcept
    {
        m_underlying.Push(arg);
        return *this;
    }

    std::string Build() const noexcept;
};

} // namespace Engine::Streams
