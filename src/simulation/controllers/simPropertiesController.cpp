#include <simulation/controllers/simPropertiesController.hpp>

#include "simulation/model/simulation/timeFunctions/constantFunction.hpp"


SimulationProperties SimPropertiesController::GetDefaultProperties() {
    return {
        .initialMassPosition = -7.f,
        .initialMassVelocity = 0.f,
        .deltaT = 0.01,
        .mass = 1.f,
        .dampingCoef = 0.1f,
        .springCoef = 5.f,
        .externalForce = std::make_unique<ConstantFunction>(0.f),
        .springFreeEndPosition = std::make_unique<ConstantFunction>(0.f),
    };
}
