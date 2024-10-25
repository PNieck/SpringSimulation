#pragma once

#include <glad/glad.h>

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <string>


class Shader {
public:
    unsigned int id;

    Shader(
        const char* vertexPath,
        const char* fragmentPath,
        const char* tesselationControlPath = nullptr,
        const char* tesselationEvaluationPath = nullptr,
        const char* geometryPath = nullptr
    );

    ~Shader();

    void use() const
        { glUseProgram(id); }

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec4(const std::string& name, const glm::vec4& vec) const;

private:
    [[nodiscard]]
    int findUniformLocation(const std::string &name) const;

    static unsigned int compileSingleShader(const char* path, GLenum shaderType);
};


class UniformNotFoundInShader final : std::exception {
public:
    [[nodiscard]]
    const char * what() const noexcept override;
};
