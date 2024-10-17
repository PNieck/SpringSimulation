#include <simulation/views/simInformationView.hpp>

#include "imgui.h"


void SimulationInformationView::Render(const SimulationResultsRepo &repo)
{
    ImGui::Begin(WindowName());

    ImGui::SeparatorText("Kinematics");
    ImGui::Text("Position: %.3f", repo.GetPosition().back());
    ImGui::Text("Velocity: %.3f", repo.GetVelocities().back());
    ImGui::Text("Acceleration: %.3f", repo.GetAccelerations().back());

    ImGui::SeparatorText("Forces");
    ImGui::Text("Spring force: %.3f", repo.GetSpringForces().back());
    ImGui::Text("Damping force: %.3f", repo.GetDampingForces().back());
    ImGui::Text("External force: %.3f", repo.GetExternalForces().back());

    ImGui::SeparatorText("Other");
    ImGui::Text("Time: %.3f", repo.GetTimes().back());
    ImGui::Text("Spring free end position: %.3f", repo.GetSpringFreeEndPositions().back());

    ImGui::End();
}
