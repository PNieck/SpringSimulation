#pragma once

#include "simulationProperties.hpp"
#include "simulationResult.hpp"

#include <mutex>


class Simulation {
public:
    explicit Simulation(SimulationProperties&& properties);

    void UpdateSimulation();

    [[nodiscard]]
    SimulationResult GetResult();

    void Restart();

private:
    [[nodiscard]]
    SpringState NewState();

    [[nodiscard]]
    float NewPosition() const;

    [[nodiscard]]
    float NewVelocity(float newPosition) const;

    [[nodiscard]]
    float NewAcceleration(float newPosition) const;

    [[nodiscard]]
    float RestoringForce(const SpringState& state) const;

    [[nodiscard]]
    float DampingForce(const SpringState& state) const;

    SpringState actSpringState;
    SpringState prevSpringState;
    SimulationProperties simProps;

    std::mutex springStateMutex;
};
