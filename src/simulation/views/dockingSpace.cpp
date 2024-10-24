#include <simulation/views/dockingSpace.hpp>

#include "imgui_internal.h"

#include <simulation/views/simulationStartStop.hpp>
#include <simulation/views/propertiesEditor.hpp>
#include <simulation/views/forcesGraph.hpp>
#include <simulation/views/trajectoryGraph.hpp>
#include <simulation/views/springStateGraph.hpp>
#include <simulation/views/simInformationView.hpp>


DockingSpace::DockingSpace()
{
    windowFlags = ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus |
        ImGuiWindowFlags_NoBackground;

    dockNodeFlags = ImGuiDockNodeFlags_PassthruCentralNode;
}


void DockingSpace::Render()
{
    const ImGuiViewport *viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->Pos);
    ImGui::SetNextWindowSize(viewport->Size);
    ImGui::SetNextWindowViewport(viewport->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

    ImGui::Begin("DockSpace", nullptr, windowFlags);
    ImGui::PopStyleVar();
    ImGui::PopStyleVar(2);

    // DockSpace
    if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_DockingEnable)
    {
        ImGuiID mainDockId = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(mainDockId, ImVec2(0.0f, 0.0f), dockNodeFlags);

        if (firstRender)
        {
            firstRender = false;

            ImGui::DockBuilderRemoveNode(mainDockId); // clear any previous layout
            ImGui::DockBuilderAddNode(mainDockId, dockNodeFlags | ImGuiDockNodeFlags_DockSpace);
            ImGui::DockBuilderSetNodeSize(mainDockId, viewport->Size);

            auto leftUpDockId = ImGui::DockBuilderSplitNode(
                mainDockId, ImGuiDir_Left, 0.3f, nullptr, &mainDockId);
            auto leftMiddleDockId = ImGui::DockBuilderSplitNode(
                leftUpDockId, ImGuiDir_Down, 0.75f, nullptr,&leftUpDockId);
            const auto leftDownDockId = ImGui::DockBuilderSplitNode(
                leftMiddleDockId, ImGuiDir_Down, 0.5f, nullptr, &leftMiddleDockId);

            auto rightUpDockId = ImGui::DockBuilderSplitNode(
                mainDockId, ImGuiDir_Right, 0.5f, nullptr, &mainDockId);
            const auto rightDownDockId = ImGui::DockBuilderSplitNode(
                rightUpDockId, ImGuiDir_Down, 0.7f, nullptr, &rightUpDockId);

            const auto mainDownDockId = ImGui::DockBuilderSplitNode(
                mainDockId, ImGuiDir_Down, 0.5f, nullptr, &mainDockId);

            ImGui::DockBuilderDockWindow(SimulationStartStop::WindowName(), leftUpDockId);
            ImGui::DockBuilderDockWindow(PropertiesEditor::WindowName(), leftMiddleDockId);
            ImGui::DockBuilderDockWindow(SimulationInformationView::WindowName(), leftDownDockId);

            ImGui::DockBuilderDockWindow(ForcesGraph::WindowName(), rightUpDockId);
            ImGui::DockBuilderDockWindow(TrajectoryGraph::WindowName(), rightDownDockId);
            ImGui::DockBuilderDockWindow(SpringStateGraph::WindowName(), mainDownDockId);

            ImGui::DockBuilderFinish(mainDockId);
        }
    }

    ImGui::End();
}
