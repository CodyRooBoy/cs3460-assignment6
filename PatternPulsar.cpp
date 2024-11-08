#include "PatternPulsar.hpp"

std::uint8_t PatternPulsar::getSizeX() const
{
    return 13;
}

std::uint8_t PatternPulsar::getSizeY() const
{
    return 13;
}

bool PatternPulsar::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x < 13 && y < 13)
    {
        static const bool cells[13][13] = {
            { false, false, true, true, true, false, false, false, true, true, true, false, false },
            { false, false, false, false, false, false, false, false, false, false, false, false, false },
            { true, false, false, false, false, true, false, true, false, false, false, false, true },
            { true, false, false, false, false, true, false, true, false, false, false, false, true },
            { true, false, false, false, false, true, false, true, false, false, false, false, true },
            { false, false, true, true, true, false, false, false, true, true, true, false, false },
            { false, false, false, false, false, false, false, false, false, false, false, false, false },
            { false, false, true, true, true, false, false, false, true, true, true, false, false },
            { true, false, false, false, false, true, false, true, false, false, false, false, true },
            { true, false, false, false, false, true, false, true, false, false, false, false, true },
            { true, false, false, false, false, true, false, true, false, false, false, false, true },
            { false, false, false, false, false, false, false, false, false, false, false, false, false },
            { false, false, true, true, true, false, false, false, true, true, true, false, false }
        };
        return cells[y][x];
    }
    else
    {
        return false;
    }
}