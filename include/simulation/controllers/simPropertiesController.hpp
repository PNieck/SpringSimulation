#pragma once

#include "simulation/model/simulation/simulationProperties.hpp"
#include "simulation/model/simulation/timeFunctions/constantFunction.hpp"
#include "simulation/model/simulation/timeFunctions/sharpFunction.hpp"


class SimPropertiesController {
public:
    static SimulationProperties GetDefaultProperties();

    static std::unique_ptr<ConstantFunction> GetDefaultConstantFunction()
        { return std::make_unique<ConstantFunction>(0.f); }

    static  std::unique_ptr<SharpFunction> GetDefaultSharpFunction()
        { return std::make_unique<SharpFunction>(2.f, 2.f); }
};
