#pragma once

class MainController;


class PropertiesEditor {
public:
    explicit PropertiesEditor(MainController& controller):
        controller(controller) {}

    void Render() const;

    [[nodiscard]]
    static const char* WindowName()
        { return "Properties editor"; }

private:
    MainController& controller;
};
