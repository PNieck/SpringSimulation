#include <simulation/controllers/mainController.hpp>


MainController::MainController(GLFWwindow *window):
    guiController(window), model(SimPropertiesController::GetDefaultProperties())
{
    model.StartSimulation();
}


void MainController::Update()
{
    const auto simulationState = model.GetSpringState();
    repo.AddNewResult(simulationState);
}


void MainController::Render()
{
    guiController.Render(repo);
}
