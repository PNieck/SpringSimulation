#pragma once

#include "timeFunction.hpp"

#include <cmath>


class SharpCyclicFunction final : public TimeFunction {
public:
    SharpCyclicFunction(const float amplitude, const float frequency, const float phaseShift):
        amplitude(amplitude), frequency(frequency), phaseShift(phaseShift) {}

    [[nodiscard]]
    float Value(const float t) const override
    {
        return amplitude * sgn(std::sin(frequency*t + phaseShift));
    }

    void Accept(FunctionVisitor &visitor) const override
        { visitor.VisitSharpCyclicFunction(*this); }

    float amplitude;
    float frequency;
    float phaseShift;

private:
    static float sgn(const float v)
        { return (v > 0) ? 1.f : -1.f; }
};
