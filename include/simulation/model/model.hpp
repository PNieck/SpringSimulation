#pragma once

#include "timedLoop.hpp"
#include "simulation.hpp"


class Model {
public:
    explicit Model(SimulationProperties&& props);

    inline void StartSimulation()
        { timedLoop.Start(); }

    inline void EndSimulation()
        { timedLoop.End(); }

    [[nodiscard]]
    SpringState GetSpringState()
        { return simulation.GetState(); }

private:
    TimedLoop timedLoop;
    Simulation simulation;
};
