#pragma once

class ConstantFunction;


class FunctionVisitor {
public:
    virtual ~FunctionVisitor() = default;

    virtual void VisitConstantFunction(const ConstantFunction& function) = 0;
};