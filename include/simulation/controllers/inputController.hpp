#pragma once

#include "../views/simulationStartStop.hpp"
#include "../views/propertiesEditor.hpp"


class InputController {
public:
    explicit InputController(MainController& controller):
        startStopHandler(controller), propertiesEditor(controller) {}

    void Render()
    {
        startStopHandler.Render();
        propertiesEditor.Render();
    }

private:
    SimulationStartStop startStopHandler;
    PropertiesEditor propertiesEditor;
};
