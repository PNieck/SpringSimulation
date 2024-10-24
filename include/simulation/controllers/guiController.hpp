#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "plotController.hpp"
#include "inputController.hpp"

#include "../views/dockingSpace.hpp"

#include "../model/simulationResultsRepo.hpp"


class GuiController {
public:
    explicit GuiController(GLFWwindow* window, MainController& controller);
    ~GuiController();

    void Render(const SimulationResultsRepo& repo);

private:

    PlotController plotController;
    InputController inputController;

    DockingSpace dockingSpace;
};
