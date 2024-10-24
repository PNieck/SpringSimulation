#include <simulation/model/model.hpp>


Model::Model(SimulationProperties&& props):
    timedLoop(static_cast<int>(props.deltaT * 1000.f), [this] { simulation.UpdateSimulation(); }),
    simulation(std::move(props))
{
}


void Model::SetProperties(SimulationProperties &&props)
{
    const bool simRuns = IsSimulationRunning();

    if (simRuns)
        EndSimulation();

    timedLoop.ChangePeriod(static_cast<int>(props.deltaT * 1000.f));
    simulation.SetProperties(std::move(props));

    if (simRuns)
        StartSimulation();
}
