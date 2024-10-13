#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "plotController.hpp"

#include "../views/dockingSpace.hpp"
#include "../views/optionsPanel.hpp"

#include "../model/springState.hpp"


class GuiController {
public:
    explicit GuiController(GLFWwindow* window);
    ~GuiController();

    void Update(const SpringState& state);
    void Render() const;

private:

    PlotController plotController;

    DockingSpace dockingSpace;
    OptionsPanel optionsPanel;
};
