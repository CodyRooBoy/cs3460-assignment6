#pragma once

#include "LifeSimulator.hpp"
#include "rlutil.h"

#include <iostream>
#include <vector>

class Renderer
{
  public:
    virtual void render(const LifeSimulator& simulation) = 0;
};