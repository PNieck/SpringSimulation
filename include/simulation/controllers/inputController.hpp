#pragma once

#include "../views/simulationStartStop.hpp"


class InputController {
public:
    explicit InputController(MainController& controller):
        startStopHandler(controller) {}

    void Render() const
        { startStopHandler.Render(); }

private:
    SimulationStartStop startStopHandler;
};
