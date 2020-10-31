//
// Created by kyle on 10/30/20.
//

#pragma once

#include <gsl/gsl>
#include <memory>
namespace Engine
{

class Application
{
  public:
    Application() = default;
    virtual ~Application() = default;
    Application(const Application &) = default;
    Application(Application &&) = default;
    Application &operator=(const Application &) = default;
    Application &operator=(Application &&) = default;
    void Run();
};

std::shared_ptr<Application> CreateApplication(gsl::span<const char *> args);

} // namespace Engine
