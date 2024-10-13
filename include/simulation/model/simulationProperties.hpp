#pragma once

#include "timeFunctions/timeFunction.hpp"

#include <memory>


class SimulationProperties {
public:
    float initialMassPosition;
    float initialMassVelocity;
    float deltaT;               // In seconds
    float mass;                 // In kilograms
    float dampingCoef;
    float springCoef;
    std::unique_ptr<TimeFunction> externalForce;
    std::unique_ptr<TimeFunction> springFreeEndPosition;
};
