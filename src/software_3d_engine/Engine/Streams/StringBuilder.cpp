//
// Created by kyle on 10/30/20.
//

#include "StringBuilder.hpp"
Engine::Streams::StringBuilder::StringBuilder() noexcept
    : m_ss(), m_underlying(m_ss)
{
}
std::string Engine::Streams::StringBuilder::Build() const noexcept
{
    return m_ss.str();
}
