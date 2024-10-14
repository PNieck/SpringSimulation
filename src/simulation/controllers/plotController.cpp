#include <simulation/controllers/plotController.hpp>

#include <implot.h>


PlotController::PlotController()
{
    ImPlot::CreateContext();
}


PlotController::~PlotController()
{
    ImPlot::DestroyContext();
}


void PlotController::Update(const SimulationResult& state)
{
    springStateGraph.Update(state);
}


void PlotController::Render() const
{
    ImPlot::ShowDemoWindow();

    springStateGraph.Render();
}
