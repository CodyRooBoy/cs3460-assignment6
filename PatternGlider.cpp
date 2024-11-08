#include "PatternGlider.hpp"

std::uint8_t PatternGlider::getSizeX() const
{
    return 3;
}

std::uint8_t PatternGlider::getSizeY() const
{
    return 3;
}

bool PatternGlider::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x < 3 && y < 3)
    {
        static const bool cells[3][3] = {
            { false, false, true },
            { true, false, true },
            { false, true, true }
        };
        return cells[y][x];
    }
    else
    {
        return false;
    }
}