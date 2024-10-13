#pragma once


class TimeFunction {
public:
    virtual ~TimeFunction() = default;

    virtual float Value(float t) const = 0;
};
