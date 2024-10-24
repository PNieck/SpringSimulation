#pragma once

class ConstantFunction;
class SharpFunction;
class SharpCyclicFunction;
class SinusoidalFunction;


class FunctionVisitor {
public:
    virtual ~FunctionVisitor() = default;

    virtual void VisitConstantFunction(const ConstantFunction&) = 0;

    virtual void VisitSharpFunction(const SharpFunction&) = 0;

    virtual  void VisitSharpCyclicFunction(const SharpCyclicFunction&) = 0;

    virtual  void VisitSinusoidalFunction(const SinusoidalFunction&) = 0;
};