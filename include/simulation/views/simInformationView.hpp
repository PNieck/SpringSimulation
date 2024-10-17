#pragma once

#include "../model/simulationResultsRepo.hpp"


class SimulationInformationView {
public:
    static void Render(const SimulationResultsRepo& repo);

    [[nodiscard]]
    static const char* WindowName()
        { return "Simulation Information"; }
};
