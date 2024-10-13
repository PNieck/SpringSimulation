#include <simulation/model/simulation.hpp>

Simulation::Simulation(SimulationProperties&& properties):
    actSpringState(properties), prevSpringState(properties), simProps(std::move(properties))
{
}

void Simulation::UpdateSimulation()
{
    std::lock_guard quard(springStateMutex);

    const auto tmp = NewState();
    prevSpringState = actSpringState;
    actSpringState = tmp;
}


SpringState Simulation::GetState()
{
    std::lock_guard quard(springStateMutex);

    return prevSpringState;
}


SpringState Simulation::NewState()
{
    SpringState result;

    result.t = actSpringState.t + simProps.deltaT;
    result.x = NewPosition();
    actSpringState.xt = NewVelocity(result.x);
    actSpringState.xtt = NewAcceleration(result.x);

    return result;
}

float Simulation::NewPosition() const
{
    const float actSpringLen = simProps.springFreeEndPosition->Value(actSpringState.t) - actSpringState.x;
    const float actRestoringForce = simProps.springCoef * actSpringLen;
    const float actExternForce = simProps.externalForce->Value(actSpringState.t);

    const float deltaSq = simProps.deltaT * simProps.deltaT;

    const float coef = simProps.dampingCoef * simProps.deltaT / 2.f;

    return (deltaSq*actRestoringForce + coef*prevSpringState.x + deltaSq*actExternForce +
        2.f*simProps.mass*actSpringState.x - simProps.mass*prevSpringState.x) / (simProps.mass + coef);
}


float Simulation::NewVelocity(float newPosition) const {
    return (newPosition - prevSpringState.x) / (2.f * simProps.deltaT);
}


float Simulation::NewAcceleration(float newPosition) const {
    return (newPosition - 2.f*actSpringState.x + prevSpringState.x) / (simProps.deltaT * simProps.deltaT);
}
