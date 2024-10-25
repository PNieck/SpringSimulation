#pragma once

#include "simulation/model/simulationResultsRepo.hpp"
#include "shaders/stdShader.hpp"
#include "mesh.hpp"

#include <vector>


class SpringVisualization {
public:
    SpringVisualization();
    ~SpringVisualization();

    void Render(const SimulationResultsRepo &repo);

    [[nodiscard]]
    static const char* WindowName()
        { return "Spring Visualization"; }

private:
    unsigned int fbo = 0;
    unsigned int textureColorbuffer = 0;
    StdShader shader;
    Mesh springMesh;

    float scale = 10.f;

    [[nodiscard]]
    std::vector<float> GenerateVertices(const SimulationResultsRepo &repo) const;

    [[nodiscard]]
    std::vector<unsigned int> GenerateIndices() const;
};
