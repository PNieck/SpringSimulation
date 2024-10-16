#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "plotController.hpp"

#include "../views/dockingSpace.hpp"
#include "../views/optionsPanel.hpp"

#include "../model/simulationResultsRepo.hpp"


class GuiController {
public:
    explicit GuiController(GLFWwindow* window);
    ~GuiController();

    void Render(const SimulationResultsRepo& repo);

private:

    PlotController plotController;

    DockingSpace dockingSpace;
    OptionsPanel optionsPanel;
};
