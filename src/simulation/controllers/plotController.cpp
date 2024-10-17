#include <simulation/controllers/plotController.hpp>

#include <simulation/views/forcesGraph.hpp>
#include <simulation/views/springStateGraph.hpp>
#include <simulation/views/trajectoryGraph.hpp>

#include <implot.h>


PlotController::PlotController()
{
    ImPlot::CreateContext();
}


PlotController::~PlotController()
{
    ImPlot::DestroyContext();
}


void PlotController::Render(const SimulationResultsRepo &repo) const
{
    ImPlot::ShowDemoWindow();

    SpringStateGraph::Render(repo);
    ForcesGraph::Render(repo);
    TrajectoryGraph::Render(repo);
}
