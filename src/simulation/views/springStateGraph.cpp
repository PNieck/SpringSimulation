#include <simulation/views/springStateGraph.hpp>

#include "implot.h"


void SpringStateGraph::Render(const SimulationResultsRepo &repo)
{
    ImGui::Begin(WindowName());

    if (ImPlot::BeginPlot("Graphs of position, velocity and acceleration")) {
        const int vecLen = repo.Size();
        const auto& times = repo.GetTimes();

        ImPlot::SetupAxes("t [s]","value");
        ImPlot::SetupAxesLimits(0,60,-40,40);
        ImPlot::PlotLine("x(t)", times.data(), repo.GetPosition().data(), vecLen);
        ImPlot::PlotLine("xt(t)", times.data(), repo.GetVelocities().data(), vecLen);
        ImPlot::PlotLine("xtt(t)", times.data(), repo.GetAccelerations().data(), vecLen);
        ImPlot::EndPlot();
    }

    ImGui::End();
}
