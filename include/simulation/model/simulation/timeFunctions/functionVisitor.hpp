#pragma once

class ConstantFunction;
class SharpFunction;


class FunctionVisitor {
public:
    virtual ~FunctionVisitor() = default;

    virtual void VisitConstantFunction(const ConstantFunction& function) = 0;

    virtual void VisitSharpFunction(const SharpFunction& function) = 0;
};