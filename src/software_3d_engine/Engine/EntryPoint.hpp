//
// Created by kyle on 10/30/20.
//

#pragma once

#include "Application.hpp"

int main(int argc, const char* argv[])
{
    gsl::span args(argv, argc);
    auto application = Engine::CreateApplication(args);
    application->Run();
    return 0;
}
