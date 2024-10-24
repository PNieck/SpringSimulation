#pragma once

#include "timeFunction.hpp"


class SharpFunction final : public TimeFunction {
public:
    SharpFunction(float value, float timeThreshold):
        value(value), timeThreshold(timeThreshold) {}

    [[nodiscard]]
    float Value(const float t) const override
    {
        if (t < timeThreshold)
            return 0.f;

        return value;
    }

    void Accept(FunctionVisitor &visitor) const override
        { visitor.VisitSharpFunction(*this); }

    float value;
    float timeThreshold;
};
