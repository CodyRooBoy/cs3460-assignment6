#include "RendererConsole.hpp"

RendererConsole::RendererConsole(const LifeSimulator& simulation) :
    previousState(simulation.getSizeX(), std::vector<bool>(simulation.getSizeY(), false)) {}

void RendererConsole::render(const LifeSimulator& simulation)
{
    if (firstRender)
    {
        rlutil::cls();
        rlutil::hidecursor();
        firstRender = false;
    }

    const auto sizeX = simulation.getSizeX();
    const auto sizeY = simulation.getSizeY();

    for (std::uint8_t x = 0; x < sizeX; ++x)
    {
        for (std::uint8_t y = 0; y < sizeY; ++y)
        {
            bool currentCell = simulation.getCell(x, y);
            bool previousCell = previousState[x][y];

            if (currentCell != previousCell)
            {
                rlutil::locate(x + 1, y + 1);
                if (currentCell)
                {
                    rlutil::setChar('*');
                }
                else
                {
                    rlutil::setChar(' ');
                }
                previousState[x][y] = currentCell;
            }
        }
    }

    rlutil::showcursor();
    std::cout << std::flush;
}