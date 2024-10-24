#pragma once

#include "timeFunction.hpp"

#include <cmath>


class SinusoidalFunction final : public TimeFunction {
public:
    SinusoidalFunction(const float amplitude, const float frequency, const float phaseShift):
        amplitude(amplitude), frequency(frequency), phaseShift(phaseShift) {}

    [[nodiscard]] float Value(const float t) const override
        { return amplitude * std::sin(frequency * t + phaseShift); }

    void Accept(FunctionVisitor &visitor) const override
        { visitor.VisitSinusoidalFunction(*this); }

    float amplitude;
    float frequency;
    float phaseShift;
};
