#pragma once

#include "timeFunction.hpp"


class ConstantFunction final : public TimeFunction {
public:
    explicit ConstantFunction(const float value = 0.f):
        value(value) {}

    [[nodiscard]]
    float Value(float t) const override {
        return value;
    }

    void Accept(FunctionVisitor &visitor) const override
        { visitor.VisitConstantFunction(*this); }

    float value;
};
