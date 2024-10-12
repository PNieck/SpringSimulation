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


void PlotController::Render() const
{
    ImPlot::ShowDemoWindow();
}
