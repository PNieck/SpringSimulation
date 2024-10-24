#include <simulation/views/forcesGraph.hpp>

#include "imgui.h"
#include "implot.h"


void ForcesGraph::Render(const SimulationResultsRepo &repo)
{
    ImGui::Begin(WindowName());

    if (ImPlot::BeginPlot("Graph of forces (and spring free end position")) {
        const int vecLen = repo.Size();
        const auto& times = repo.GetTimes();

        ImPlot::SetupLegend(ImPlotLocation_North | ImPlotLocation_East, 0);

        ImPlot::SetupAxes("t [s]","value");
        ImPlot::SetupAxesLimits(0,60,-40,40);
        ImPlot::PlotLine("spring force [N]", times.data(), repo.GetSpringForces().data(), vecLen);
        ImPlot::PlotLine("damping force [N]", times.data(), repo.GetDampingForces().data(), vecLen);
        ImPlot::PlotLine("external force [N]", times.data(), repo.GetExternalForces().data(), vecLen);
        ImPlot::PlotLine("free end position [m]", times.data(), repo.GetSpringFreeEndPositions().data(), vecLen);
        ImPlot::EndPlot();
    }

    ImGui::End();
}
