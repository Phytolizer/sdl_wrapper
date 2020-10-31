//
// Created by kyle on 10/30/20.
//

#include "InputStream.hpp"
Engine::Streams::InputStream::InputStream(std::istream &underlying)
    : m_underlying(underlying)
{
}
