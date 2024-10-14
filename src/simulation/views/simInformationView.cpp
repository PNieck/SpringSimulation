#include <simulation/views/simInformationView.hpp>

#include "imgui.h"


void SimulationInformationView::Render() const {
    ImGui::Begin(WindowName());

    ImGui::SeparatorText("Kinematics");
    ImGui::Text("Position: %.3f", actSimResult.x);
    ImGui::Text("Velocity: %.3f", actSimResult.xt);
    ImGui::Text("Acceleration: %.3f", actSimResult.xtt);

    ImGui::SeparatorText("Forces");
    ImGui::Text("Spring force: %.3f", actSimResult.springForce);
    ImGui::Text("Damping force: %.3f", actSimResult.dampingForce);
    ImGui::Text("External force: %.3f", actSimResult.externalForce);

    ImGui::SeparatorText("Other");
    ImGui::Text("Time: %.3f", actSimResult.t);
    ImGui::Text("Spring free end position: %.3f", actSimResult.springFreeEndPosition);

    ImGui::End();
}
