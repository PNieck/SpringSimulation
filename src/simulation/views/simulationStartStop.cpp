#include <simulation/views/simulationStartStop.hpp>

#include <imgui.h>

#include "simulation/controllers/mainController.hpp"


void SimulationStartStop::Render() const
{
    ImGui::Begin(WindowName());

    const bool simRuns = controller.IsSimulationRunning();

    ImGui::BeginDisabled(simRuns);
    if (ImGui::Button("Start")) {
        controller.StartSimulation();
    }
    ImGui::EndDisabled();

    ImGui::SameLine();

    ImGui::BeginDisabled(!simRuns);
    if (ImGui::Button("Stop")) {
        controller.EndSimulation();
    }

    ImGui::EndDisabled();

    ImGui::SameLine();
    if (ImGui::Button("Restart")) {
        controller.ResetSimulation();
    }

    ImGui::End();
}
