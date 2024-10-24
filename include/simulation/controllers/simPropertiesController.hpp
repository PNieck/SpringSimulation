#pragma once

#include "simulation/model/simulation/simulationProperties.hpp"
#include "simulation/model/simulation/timeFunctions/constantFunction.hpp"
#include "simulation/model/simulation/timeFunctions/sharpFunction.hpp"
#include "simulation/model/simulation/timeFunctions/sharpCyclicFunction.hpp"
#include "simulation/model/simulation/timeFunctions/sinusoidalFunction.hpp"


class SimPropertiesController {
public:
    static SimulationProperties GetDefaultProperties();

    static std::unique_ptr<ConstantFunction> GetDefaultConstantFunction()
        { return std::make_unique<ConstantFunction>(0.f); }

    static std::unique_ptr<SharpFunction> GetDefaultSharpFunction()
        { return std::make_unique<SharpFunction>(1.f, 1.f); }

    static std::unique_ptr<SharpCyclicFunction> GetDefaultSharpCyclicFunction()
        { return std::make_unique<SharpCyclicFunction>(1.f, 1.f, 0.f); }

    static std::unique_ptr<SinusoidalFunction> GetDefaultSinusoidalFunction()
        { return std::make_unique<SinusoidalFunction>(1.f, 1.f, 0.f); }
};
