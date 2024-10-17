#pragma once

#include <vector>
#include <simulation/model/simulationResult.hpp>


class TimeGraph {
public:
    TimeGraph()
        { t.reserve(maxStates); }

    inline void Update(const SimulationResult& result)
        { t.push_back(result.t); }

protected:
    static constexpr int maxStates = 10000;

    std::vector<float> t;
};
