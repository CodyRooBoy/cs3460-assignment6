#include "PatternBlock.hpp"

std::uint8_t PatternBlock::getSizeX() const
{
    return 2;
}

std::uint8_t PatternBlock::getSizeY() const
{
    return 2;
}

bool PatternBlock::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x < 2 && y < 2)
    {
        static const bool cells[2][2] = {
            { true, true },
            { true, true }
        };
        return cells[y][x];
    }
    else
    {
        return false;
    }
}
