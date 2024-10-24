#include <simulation/model/simulation/simulation.hpp>

Simulation::Simulation(SimulationProperties&& properties):
    actSpringState(properties), prevSpringState(properties), simProps(std::move(properties))
{
}


void Simulation::UpdateSimulation()
{
    std::lock_guard guard(springStateMutex);

    const auto tmp = NewState();
    prevSpringState = actSpringState;
    actSpringState = tmp;
}


SimulationResult Simulation::GetResult()
{
    std::lock_guard guard(springStateMutex);

    return {
        prevSpringState,
        RestoringForce(prevSpringState),
        DampingForce(prevSpringState),
        simProps.externalForce->Value(prevSpringState.t),
        simProps.springFreeEndPosition->Value(prevSpringState.t),
    };
}


void Simulation::Restart()
{
    std::lock_guard guard(springStateMutex);

    actSpringState = SpringState(simProps);
    prevSpringState = SpringState(simProps);
}


void Simulation::SetProperties(SimulationProperties&& properties)
{
    std::lock_guard guard(springStateMutex);

    simProps = std::move(properties);
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
    const float actRestoringForce = RestoringForce(actSpringState);
    const float actExternForce = simProps.externalForce->Value(actSpringState.t);

    const float deltaSq = simProps.deltaT * simProps.deltaT;

    const float coef = simProps.dampingCoef * simProps.deltaT / 2.f;

    return (deltaSq*actRestoringForce + coef*prevSpringState.x + deltaSq*actExternForce +
        2.f*simProps.mass*actSpringState.x - simProps.mass*prevSpringState.x) / (simProps.mass + coef);
}


float Simulation::NewVelocity(const float newPosition) const {
    return (newPosition - prevSpringState.x) / (2.f * simProps.deltaT);
}


float Simulation::NewAcceleration(const float newPosition) const {
    return (newPosition - 2.f*actSpringState.x + prevSpringState.x) / (simProps.deltaT * simProps.deltaT);
}


float Simulation::RestoringForce(const SpringState& state) const
{
    const float springLen = simProps.springFreeEndPosition->Value(state.t) - state.x;
    return simProps.springCoef * springLen;
}


float Simulation::DampingForce(const SpringState &state) const
{
    return -simProps.dampingCoef * state.xt;
}
