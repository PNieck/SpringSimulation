#pragma once

#include "springState.hpp"


class SimulationResult {
public:
    SimulationResult() = default;

    SimulationResult(const SpringState& springState,
                     const float springForce, const float dampingForce, const float externalForce,
                     const float springFreeEndPosition):
        t(springState.t),
        x(springState.x),
        xt(springState.xt),
        xtt(springState.xtt),
        springForce(springForce),
        dampingForce(dampingForce),
        externalForce(externalForce),
        springFreeEndPosition(springFreeEndPosition)
        {}


    float t;
    float x;
    float xt;
    float xtt;

    float springForce;
    float dampingForce;
    float externalForce;

    float springFreeEndPosition;
};
