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

    void StartSimulation()
        { model.StartSimulation(); }

    void EndSimulation()
        { model.EndSimulation(); }

    void ResetSimulation()
    {
        model.RestartSimulation();
        repo.Clear();
    }

    [[nodiscard]]
    bool IsSimulationRunning() const
        { return model.IsSimulationRunning(); }

    [[nodiscard]]
    const SimulationProperties& GetSimulationProperties() const
        { return model.GetProperties(); }

    void SetSimulationProperties(SimulationProperties&& properties)
        { model.SetProperties(std::move(properties)); }

private:
    GuiController guiController;
    SimPropertiesController simPropertiesController;
    Model model;
    SimulationResultsRepo repo;
};
