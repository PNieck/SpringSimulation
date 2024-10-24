#pragma once

#include "../model/simulation/simulationProperties.hpp"
#include "simulation/model/simulation/timeFunctions/constantFunction.hpp"


class SimPropertiesController {
public:
    static SimulationProperties GetDefaultProperties();

    static std::unique_ptr<ConstantFunction> GetDefaultConstantFunction()
        { return std::make_unique<ConstantFunction>(0.f); }
};
