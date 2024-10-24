#include <simulation/views/propertiesEditor.hpp>

#include <imgui.h>

#include "simulation/controllers/mainController.hpp"
#include "simulation/model/simulation/timeFunctions/constantFunction.hpp"


enum TimeFunctionsType {
    Constant = 0
};


static const char* TimeFunctionsNames[] = {
    "Constant function"
};


class TimeFunctionTypeGetter final : public FunctionVisitor {
public:
    void VisitConstantFunction(const ConstantFunction &function) override
    {
        timeFunctionType = Constant;
    }

    TimeFunctionsType timeFunctionType = Constant;
};


class TimeFunctionEditor final : public FunctionVisitor {
public:
    explicit TimeFunctionEditor(const char* id):
        id(id) {}

    void VisitConstantFunction(const ConstantFunction &function) override
    {
        value = function.value;
        ImGui::PushID(id);

        if (ImGui::DragFloat("Constant value", &value)) {
            valueChanged = true;
        }

        ImGui::PopID();
    }

    std::unique_ptr<TimeFunction> GetTimeFunction()
    {
        return std::make_unique<ConstantFunction>(value);
    }

    const char* id;
    bool valueChanged = false;

private:
    float value = 0.f;
};


void PropertiesEditor::Render() const
{
    ImGui::Begin(WindowName());

    const bool simRuns = controller.IsSimulationRunning();
    bool propertiesChanged = false;
    auto const& props = controller.GetSimulationProperties();

    ImGui::BeginDisabled(simRuns);

    float initMassPos = props.initialMassPosition;
    propertiesChanged |= ImGui::DragFloat("Initial mass position", &initMassPos);

    float initMassVel = props.initialMassVelocity;
    propertiesChanged |= ImGui::DragFloat("Initial mass velocity", &initMassVel);

    float deltaT = props.deltaT;
    propertiesChanged |= ImGui::DragFloat("Time delta", &deltaT);

    float mass = props.mass;
    propertiesChanged |= ImGui::DragFloat("Mass", &mass);

    float dampingCoef = props.dampingCoef;
    propertiesChanged |= ImGui::DragFloat("Damping coefficient", &dampingCoef);

    float springCoef = props.springCoef;
    propertiesChanged |= ImGui::DragFloat("Spring coefficient", &springCoef);

    TimeFunctionTypeGetter timeFunctionTypeGetter;
    props.externalForce->Accept(timeFunctionTypeGetter);
    int functionType = timeFunctionTypeGetter.timeFunctionType;
    TimeFunctionEditor externalForceEditor("External force editor");
    if(ImGui::Combo("External force function", &functionType, TimeFunctionsNames, IM_ARRAYSIZE(TimeFunctionsNames))) {
        propertiesChanged = true;

    }
    else {
        props.externalForce->Accept(externalForceEditor);
        propertiesChanged |= externalForceEditor.valueChanged;
    }

    props.springFreeEndPosition->Accept(timeFunctionTypeGetter);
    functionType = timeFunctionTypeGetter.timeFunctionType;
    TimeFunctionEditor springForceEditor("Spring force editor");
    if(ImGui::Combo("Spring free end position", &functionType, TimeFunctionsNames, IM_ARRAYSIZE(TimeFunctionsNames))) {
        propertiesChanged = true;

    }
    else {
        props.springFreeEndPosition->Accept(springForceEditor);
        propertiesChanged |= springForceEditor.valueChanged;
    }

    ImGui::EndDisabled();
    ImGui::End();

    if (propertiesChanged) {
        SimulationProperties newProps{
            .initialMassPosition = initMassPos,
            .initialMassVelocity = initMassVel,
            .deltaT = deltaT,
            .mass = mass,
            .dampingCoef = dampingCoef,
            .springCoef = springCoef,
            .externalForce = externalForceEditor.GetTimeFunction(),
            .springFreeEndPosition = springForceEditor.GetTimeFunction()
        };

        controller.SetSimulationProperties(std::move(newProps));
    }
}
