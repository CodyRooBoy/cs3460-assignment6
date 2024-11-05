#include "LifeSimulator.hpp"

LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY) :
    sizeX(sizeX), sizeY(sizeY)
{
}

void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY) {

}

void LifeSimulator::update()
{
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
    return false;
}