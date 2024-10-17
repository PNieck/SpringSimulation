#include  <simulation/views/trajectoryGraph.hpp>

#include "imgui.h"
#include "implot.h"


void TrajectoryGraph::Render(const SimulationResultsRepo &repo)
{
    ImGui::Begin(WindowName());

    if (ImPlot::BeginPlot("State trajectory graph")) {
        ImPlot::SetupAxes("x","xt");
        ImPlot::SetupAxesLimits(-20,20,-20,20);
        ImPlot::PlotLine("", repo.GetPosition().data(), repo.GetVelocities().data(), repo.Size());
        ImPlot::EndPlot();
    }

    ImGui::End();
}
