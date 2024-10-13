#include <simulation/model/model.hpp>


Model::Model(SimulationProperties&& props):
    timedLoop(static_cast<int>(props.deltaT * 1000.f), [this] { simulation.UpdateSimulation(); }),
    simulation(std::move(props))
{
}
