#pragma once

#include "../model/simulationResultsRepo.hpp"


class ForcesGraph {
public:
    static void Render(const SimulationResultsRepo& repo) ;

    [[nodiscard]]
    static const char* WindowName()
        { return "Forces"; }
};
