#pragma once

#include "../model/simulationResult.hpp"

#include "../views/springStateGraph.hpp"

class PlotController {
public:
    PlotController();
    ~PlotController();

    void Update(const SimulationResult& state);
    void Render() const;

private:
    SpringStateGraph springStateGraph;
};
