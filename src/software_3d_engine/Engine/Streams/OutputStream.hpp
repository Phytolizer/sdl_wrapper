//
// Created by kyle on 10/30/20.
//

#pragma once

#include <ostream>
namespace Engine::Streams
{

template <typename T>
concept OutputStreamable = requires(std::ostream &os, T arg)
{
    os << arg;
};

class OutputStream
{
    std::ostream &m_underlying;

  public:
    explicit OutputStream(std::ostream &underlying);

    template <OutputStreamable T>
    OutputStream &Push(T arg)
    {
        m_underlying << arg;
        return *this;
    }
};

} // namespace Engine::Streams
