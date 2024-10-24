#pragma once


class MainController;


class SimulationStartStop {
public:
    explicit SimulationStartStop(MainController& controller):
        controller(controller) {}

    void Render() const;

    [[nodiscard]]
    static const char* WindowName()
        { return "Start/Stop simulation"; }

private:
    MainController& controller;
};
