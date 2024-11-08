#include "PatternBlinker.hpp"

std::uint8_t PatternBlinker::getSizeX() const
{
    return 1;
}

std::uint8_t PatternBlinker::getSizeY() const
{
    return 3;
}

bool PatternBlinker::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x < 1 && y < 3)
    {
        static const bool cells[3][1] = {
            { true },
            { true },
            { true }
        };
        return cells[y][x];
    }
    else
    {
        return false;
    }
}
