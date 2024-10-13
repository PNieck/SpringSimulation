#include <simulation/controllers/mainController.hpp>


MainController::MainController(GLFWwindow *window):
    guiController(window), model(SimPropertiesController::GetDefaultProperties())
{
    model.StartSimulation();
}


void MainController::Update()
{
    const SpringState springState = model.GetSpringState();

    guiController.Update(springState);
}


void MainController::Render() const
{
    guiController.Render();
}
