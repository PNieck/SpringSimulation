#pragma once

#include "simulation/timedLoop.hpp"
#include "simulation/simulation.hpp"


class Model {
public:
    explicit Model(SimulationProperties&& props);

    inline void StartSimulation()
        { timedLoop.Start(); }

    inline void EndSimulation()
        { timedLoop.End(); }

    void RestartSimulation()
        { simulation.Restart(); }

    [[nodiscard]]
    bool IsSimulationRunning() const
        { return timedLoop.IsRunning(); }

    [[nodiscard]]
    SimulationResult GetSpringState()
        { return simulation.GetResult(); }

private:
    TimedLoop timedLoop;
    Simulation simulation;
};
