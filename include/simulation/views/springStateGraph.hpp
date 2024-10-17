#pragma once

#include "../model/simulationResultsRepo.hpp"


class SpringStateGraph {
public:
    static void Render(const SimulationResultsRepo& repo);

    [[nodiscard]]
    static const char* WindowName()
        { return "Position, velocity and acceleration"; }
};
