#pragma once

#include "../model/simulationResult.hpp"


class SimulationInformationView {
public:
    inline void Update(const SimulationResult& state)
        { actSimResult = state; }

    void Render() const;

    [[nodiscard]]
    static const char* WindowName()
        { return "Simulation Information"; }

private:
    SimulationResult actSimResult = {};
};
