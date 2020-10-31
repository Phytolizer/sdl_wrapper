//
// Created by kyle on 10/30/20.
//

#include "OutputStream.hpp"
Engine::Streams::OutputStream::OutputStream(std::ostream &underlying)
    : m_underlying(underlying)
{
}
