//
// Created by kyle on 10/30/20.
//

#pragma once

#include <string_view>
#include <system_error>

namespace Engine
{

class Error : public std::system_error
{
  public:
    Error();
    Error(std::error_code ec, std::string_view what);
};

} // namespace Engine
