#include "LifeSimulator.hpp"
#include "PatternAcorn.hpp"
#include "PatternBlinker.hpp"
#include "PatternBlock.hpp"
#include "PatternGlider.hpp"
#include "PatternGosperGliderGun.hpp"
#include "PatternPulsar.hpp"
#include "RendererConsole.hpp"

#include <chrono>
#include <thread>

int main()
{
    std::uint8_t worldWidth = rlutil::tcols();
    std::uint8_t worldHeight = rlutil::trows();

    LifeSimulator simulation(worldWidth, worldHeight);

    // PatternAcorn pattern;
    // PatternBlinker pattern;
    // PatternBlock pattern;
    // PatternGlider pattern;
    PatternGosperGliderGun pattern;
    // PatternPulsar pattern;
    simulation.insertPattern(pattern, 5, 5);

    RendererConsole renderer(simulation);

    const int numSteps = 100;

    renderer.render(simulation);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    for (int step = 0; step < numSteps; ++step)
    {
        simulation.update();
        renderer.render(simulation);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    rlutil::showcursor();

    return 0;
}