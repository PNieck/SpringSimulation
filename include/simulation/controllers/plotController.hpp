#pragma once

#include "../model/simulationResultsRepo.hpp"


class PlotController {
public:
    PlotController();
    ~PlotController();

    void Render(const SimulationResultsRepo& repo) const;
};
