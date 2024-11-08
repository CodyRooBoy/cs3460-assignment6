#pragma once

#include "Pattern.hpp"

#include <cstdint>

class PatternPulsar : public Pattern
{
  public:
    std::uint8_t getSizeX() const override;
    std::uint8_t getSizeY() const override;
    bool getCell(std::uint8_t x, std::uint8_t y) const override;
};
