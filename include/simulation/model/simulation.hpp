#pragma once

#include "simulationProperties.hpp"
#include "springState.hpp"

#include <mutex>


class Simulation {
public:
    explicit Simulation(SimulationProperties&& properties);

    void UpdateSimulation();

    [[nodiscard]]
    SpringState GetState();

private:
    [[nodiscard]]
    SpringState NewState();

    [[nodiscard]]
    float NewPosition() const;

    [[nodiscard]]
    float NewVelocity(float newPosition) const;

    [[nodiscard]]
    float NewAcceleration(float newPosition) const;

    SpringState actSpringState;
    SpringState prevSpringState;
    SimulationProperties simProps;

    std::mutex springStateMutex;
};
