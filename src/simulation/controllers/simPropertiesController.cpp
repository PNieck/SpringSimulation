#include <simulation/controllers/simPropertiesController.hpp>


SimulationProperties SimPropertiesController::GetDefaultProperties() {
    return {
        .initialMassPosition = -7.f,
        .initialMassVelocity = 0.f,
        .deltaT = 0.001,
        .mass = 1.f,
        .dampingCoef = 0.1f,
        .springCoef = 5.f,
        .externalForce = GetDefaultConstantFunction(),
        .springFreeEndPosition = GetDefaultConstantFunction(),
    };
}
