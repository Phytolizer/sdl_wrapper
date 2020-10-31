//
// Created by kyle on 10/30/20.
//

#include "Error.hpp"
Engine::Error::Error() : std::system_error({}, "")
{
}
Engine::Error::Error(std::error_code ec, std::string_view what)
    : std::system_error(ec, what.data())
{
}
