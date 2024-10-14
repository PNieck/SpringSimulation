#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "plotController.hpp"

#include "../views/dockingSpace.hpp"
#include "../views/optionsPanel.hpp"
#include "../views/simInformationView.hpp"

#include "../model/simulationResult.hpp"


class GuiController {
public:
    explicit GuiController(GLFWwindow* window);
    ~GuiController();

    void Update(const SimulationResult& result);

    void Render();

private:

    PlotController plotController;

    DockingSpace dockingSpace;
    OptionsPanel optionsPanel;
    SimulationInformationView simulationInformationView;
};
