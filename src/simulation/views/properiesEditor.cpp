#include <simulation/views/propertiesEditor.hpp>

#include <imgui.h>

#include "simulation/controllers/mainController.hpp"
#include "simulation/model/simulation/timeFunctions/constantFunction.hpp"
#include "simulation/model/simulation/timeFunctions/sharpFunction.hpp"

#include "simulation/controllers/simPropertiesController.hpp"


enum TimeFunctionsType {
    Constant = 0,
    Sharp = 1
};


static const char* TimeFunctionsNames[] = {
    "Constant function",
    "Sharp function"
};


class TimeFunctionTypeGetter final : public FunctionVisitor {
public:
    void VisitConstantFunction(const ConstantFunction &function) override
        { timeFunctionType = Constant; }

    void VisitSharpFunction(const class SharpFunction &function) override
        { timeFunctionType = Sharp; }


    TimeFunctionsType timeFunctionType = Constant;
};


class TimeFunctionEditor final : public FunctionVisitor {
public:
    explicit TimeFunctionEditor(const char* id):
        id(id) {}

    void VisitConstantFunction(const ConstantFunction &function) override
    {
        value = function.value;
        functionType = Constant;

        ImGui::PushID(id);

        if (ImGui::DragFloat("Constant value", &value))
            valueChanged = true;

        ImGui::PopID();
    }

    void VisitSharpFunction(const SharpFunction &function) override
    {
        value = function.value;
        timeThreshold = function.timeThreshold;
        functionType = Sharp;

        ImGui::PushID(id);

        if (ImGui::DragFloat("Value", &value))
            valueChanged = true;

        if (ImGui::DragFloat("TimeThreshold", &timeThreshold))
            valueChanged = true;

        ImGui::PopID();
    }

    std::unique_ptr<TimeFunction> GetTimeFunction()
    {
        switch (functionType) {
            case Constant:
                return std::make_unique<ConstantFunction>(value);

            case Sharp:
                return std::make_unique<SharpFunction>(value, timeThreshold);

            default:
                throw std::runtime_error("Invalid time function type");
        }
    }

    const char* id;
    bool valueChanged = false;

private:
    float value = 0.f;
    float timeThreshold = 0.f;
    TimeFunctionsType functionType = Constant;
};


std::unique_ptr<TimeFunction> GetDefaultTimeFunction(TimeFunctionsType type)
{
    switch (type) {
        case Constant:
            return SimPropertiesController::GetDefaultConstantFunction();

        case Sharp:
            return SimPropertiesController::GetDefaultSharpFunction();

        default:
            throw std::runtime_error("Invalid time function type");
    }
}


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
        const auto newExternalForce = GetDefaultTimeFunction(static_cast<TimeFunctionsType>(functionType));
        newExternalForce->Accept(externalForceEditor);
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
        const auto newSpringFun = GetDefaultTimeFunction(static_cast<TimeFunctionsType>(functionType));
        newSpringFun->Accept(springForceEditor);
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
