#pragma once

#include <imgui.h>


class DockingSpace {
public:
    DockingSpace();

    void Render();

private:
    bool firstRender = true;

    ImGuiWindowFlags windowFlags;
    ImGuiDockNodeFlags dockNodeFlags;
};
