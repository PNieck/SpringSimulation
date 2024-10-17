#pragma once

#include "guiController.hpp"
#include "simPropertiesController.hpp"
#include "../model/model.hpp"
#include "../model/simulationResultsRepo.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


class MainController {
public:
    explicit MainController(GLFWwindow* window);

    void Update();

    void Render();

private:
    GuiController guiController;
    SimPropertiesController simPropertiesController;
    Model model;
    SimulationResultsRepo repo;
};
