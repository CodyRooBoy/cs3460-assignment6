#include "LifeSimulator.hpp"

LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY) :
    sizeX(sizeX), sizeY(sizeY)
{
    world = std::vector<std::vector<bool>>(sizeY, std::vector<bool>(sizeX, false));
}

void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY)
{
    for (std::uint8_t y = 0; y < pattern.getSizeY(); ++y)
    {
        for (std::uint8_t x = 0; x < pattern.getSizeX(); ++x)
        {
            if (pattern.getCell(x, y) && startX + x < getSizeX() && startY + y < getSizeY())
            {
                world[startY + y][startX + x] = true;
            }
        }
    }
}

void LifeSimulator::update()
{
    std::vector<std::vector<bool>> nextWorld;
    nextWorld = std::vector<std::vector<bool>>(sizeY, std::vector<bool>(sizeX, false));

    for (std::uint8_t y = 0; y < getSizeY(); ++y)
    {
        for (std::uint8_t x = 0; x < getSizeX(); ++x)
        {
            int liveNeighbors = countNeighbors(x, y);
            bool isAlive = world[y][x];

            if (isAlive && (liveNeighbors < 2 || liveNeighbors > 3))
            {
                nextWorld[y][x] = false;
            }
            else if (!isAlive && liveNeighbors == 3)
            {
                nextWorld[y][x] = true;
            }
            else
            {
                nextWorld[y][x] = world[y][x];
            }
        }
    }

    world.swap(nextWorld);
}

std::uint8_t LifeSimulator::getSizeX() const
{
    return sizeX;
}

std::uint8_t LifeSimulator::getSizeY() const
{
    return sizeY;
}

bool LifeSimulator::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x >= getSizeX() || y >= getSizeY())
    {
        return false;
    }
    else
    {
        return world[y][x];
    }
}

int LifeSimulator::countNeighbors(std::uint8_t x, std::uint8_t y) const
{
    int count = 0;
    for (int dy = -1; dy <= 1; ++dy)
    {
        for (int dx = -1; dx <= 1; ++dx)
        {
            if (dx == 0 && dy == 0)
                continue;
            std::uint8_t nx = x + dx;
            std::uint8_t ny = y + dy;
            if (nx < getSizeX() && ny < getSizeY() && world[ny][nx])
            {
                ++count;
            }
        }
    }
    return count;
}