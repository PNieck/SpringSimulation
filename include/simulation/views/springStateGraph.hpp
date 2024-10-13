#pragma once

#include "../model/springState.hpp"

#include <vector>


class SpringStateGraph {
public:
    SpringStateGraph();

    void Update(const SpringState& state);

    void Render() const;

private:
    static constexpr int maxStates = 10000;

    std::vector<float> t;
    std::vector<float> x;
    std::vector<float> xt;
    std::vector<float> xtt;
};
