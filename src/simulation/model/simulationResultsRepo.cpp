#include <simulation/model/simulationResultsRepo.hpp>


SimulationResultsRepo::SimulationResultsRepo()
{
    t.reserve(initSize);
    x.reserve(initSize);
    xt.reserve(initSize);
    xtt.reserve(initSize);
    springForce.reserve(initSize);
    dampingForce.reserve(initSize);
    externalForce.reserve(initSize);
    springFreeEndPosition.reserve(initSize);
}


void SimulationResultsRepo::AddNewResult(const SimulationResult &newResult)
{
    t.push_back(newResult.t);
    x.push_back(newResult.x);
    xt.push_back(newResult.xt);
    xtt.push_back(newResult.xtt);
    springForce.push_back(newResult.springForce);
    dampingForce.push_back(newResult.dampingForce);
    externalForce.push_back(newResult.externalForce);
    springFreeEndPosition.push_back(newResult.springFreeEndPosition);
}
