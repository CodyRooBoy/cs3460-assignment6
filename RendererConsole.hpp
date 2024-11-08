#pragma once

#include "LifeSimulator.hpp"
#include "Renderer.hpp"

class RendererConsole : public Renderer
{
  public:
    RendererConsole(const LifeSimulator& simulation);

    void render(const LifeSimulator& simulation) override;

  private:
    bool firstRender = true;
    std::vector<std::vector<bool>> previousState;
};