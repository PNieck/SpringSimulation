#pragma once

#include "../model/simulationResultsRepo.hpp"


class TrajectoryGraph {
public:
    static void Render(const SimulationResultsRepo& repo) ;

    [[nodiscard]]
    static const char* WindowName()
    { return "Trajectory"; }
};

