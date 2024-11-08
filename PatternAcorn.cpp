#include "PatternAcorn.hpp"

std::uint8_t PatternAcorn::getSizeX() const
{
    return 7;
}

std::uint8_t PatternAcorn::getSizeY() const
{
    return 3;
}

bool PatternAcorn::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x < 7 && y < 3)
    {
        static const bool cells[3][7] = {
            { false, true, false, false, false, false, false },
            { false, false, false, true, false, false, false },
            { true, true, false, false, true, true, true }
        };
        return cells[y][x];
    }
    else
    {
        return false;
    }
}