#pragma once

#include <vector>

#include "simulation/simulationResult.hpp"


class SimulationResultsRepo {
public:
    SimulationResultsRepo();

    void AddNewResult(const SimulationResult& newResult);

    [[nodiscard]]
    const std::vector<float>& GetTimes() const
        { return t; }

    [[nodiscard]]
    const std::vector<float>& GetPosition() const
        { return x; }

    [[nodiscard]]
    const std::vector<float>& GetVelocities() const
        { return xt; }

    [[nodiscard]]
    const std::vector<float>& GetAccelerations() const
        { return xtt; }

    [[nodiscard]]
    const std::vector<float>& GetSpringForces() const
        { return springForce; }

    [[nodiscard]]
    const std::vector<float>& GetDampingForces() const
        { return dampingForce; }

    [[nodiscard]]
    const std::vector<float>& GetExternalForces() const
        { return externalForce; }

    [[nodiscard]]
    const std::vector<float>& GetSpringFreeEndPositions() const
        { return springFreeEndPosition; }

    [[nodiscard]]
    int Size() const
        { return static_cast<int>(t.size()); }

    [[nodiscard]]
    bool Empty() const
        { return t.empty(); }

    void Clear();

private:
    static constexpr int initSize = 10000;

    std::vector<float> t;
    std::vector<float> x;
    std::vector<float> xt;
    std::vector<float> xtt;

    std::vector<float> springForce;
    std::vector<float> dampingForce;
    std::vector<float> externalForce;

    std::vector<float> springFreeEndPosition;
};
