//
// Created by kyle on 10/30/20.
//

#include <Engine.hpp>
#include <Engine/Application.hpp>

class Sandbox : public Engine::Application
{
  public:
    Sandbox() = default;
};

std::shared_ptr<Engine::Application> Engine::CreateApplication(gsl::span<const char *> args)
{
    return std::make_shared<Sandbox>();
}
