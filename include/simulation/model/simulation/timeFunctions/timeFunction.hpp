#pragma once

#include "functionVisitor.hpp"


class TimeFunction {
public:
    virtual ~TimeFunction() = default;

    [[nodiscard]]
    virtual float Value(float t) const = 0;

    virtual void Accept(FunctionVisitor& visitor) const = 0;
};
