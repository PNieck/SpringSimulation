#pragma once

#include "../views/springStateGraph.hpp"

class PlotController {
public:
    PlotController();
    ~PlotController();

    void Update(const SpringState& state);
    void Render() const;

private:
    SpringStateGraph springStateGraph;
};
