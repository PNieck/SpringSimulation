#pragma once

#include "simulationProperties.hpp"


class SpringState {
public:
     explicit SpringState(const SimulationProperties& properties):
          t(0.f), x(properties.initialMassPosition),
          xt(properties.initialMassVelocity), xtt(0.f) {}

     SpringState():
          t(0.f), x(0.f), xt(0.f), xtt(0.f) {}

     float t;
     float x;
     float xt;
     float xtt;
};
