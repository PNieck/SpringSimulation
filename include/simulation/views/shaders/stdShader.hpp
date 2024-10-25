#pragma once

#include "shader.hpp"


class StdShader : private Shader {
public:
    StdShader():
        Shader(
            "../../shaders/stdShader.vert",
            "../../shaders/stdShader.frag"
        ) {}

    void SetColor(const glm::vec4& color) const
        { setVec4("color", color); }

    void Use() const
        { use(); }
};