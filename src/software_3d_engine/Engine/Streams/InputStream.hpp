//
// Created by kyle on 10/30/20.
//

#pragma once

#include <istream>

namespace Engine::Streams
{

template <typename T>
concept InputStreamable = requires(std::istream &is, T arg)
{
    T();
    is >> arg;
};

class InputStream
{
    std::istream &m_underlying;

  public:
    explicit InputStream(std::istream &underlying);

    template <InputStreamable T> T Pull()
    {
        T out;
        m_underlying >> out;
        return out;
    }
};

}
