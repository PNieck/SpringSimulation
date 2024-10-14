#include <simulation/views/springStateGraph.hpp>

#include "implot.h"


SpringStateGraph::SpringStateGraph()
{
    t.reserve(maxStates);
    x.reserve(maxStates);
    xt.reserve(maxStates);
    xtt.reserve(maxStates);
}


void SpringStateGraph::Update(const SimulationResult& state)
{
    t.push_back(state.t);
    x.push_back(state.x);
    xt.push_back(state.xt);
    xtt.push_back(state.xtt);
}


void SpringStateGraph::Render() const
{
    ImGui::Begin(WindowName());

    if (ImPlot::BeginPlot("Graphs of position, velocity and acceleration")) {
        ImPlot::SetupAxes("t [s]","y");
        ImPlot::SetupAxesLimits(0,60,-40,40);
        ImPlot::PlotLine("x(t)", t.data(), x.data(), t.size());
        ImPlot::PlotLine("xt(t)", t.data(), xt.data(), t.size());
        ImPlot::PlotLine("xtt(t)", t.data(), xtt.data(), t.size());
        ImPlot::EndPlot();
    }

    ImGui::End();
}
