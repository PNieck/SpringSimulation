#pragma once

#include "timeFunction.hpp"


class ConstantFunction final : public TimeFunction {
public:
    explicit ConstantFunction(const float value = 0.f):
        value(value) {}

    float Value(float t) const override {
        return value;
    }

private:
    float value;
};
