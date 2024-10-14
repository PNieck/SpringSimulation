#pragma once

#include <simulation/model/simulationResult.hpp>

#include <vector>



class SpringStateGraph {
public:
    SpringStateGraph();

    void Update(const SimulationResult& state);

    void Render() const;

    [[nodiscard]]
    static const char* WindowName()
        { return "Position, velocity and acceleration"; }

private:
    static constexpr int maxStates = 10000;

    std::vector<float> t;
    std::vector<float> x;
    std::vector<float> xt;
    std::vector<float> xtt;
};
