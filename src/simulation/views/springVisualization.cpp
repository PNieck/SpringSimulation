#include <simulation/views/springVisualization.hpp>

#include "glad/glad.h"

#include <iostream>

#include "imgui.h"


SpringVisualization::SpringVisualization()
{
    glGenFramebuffers(1, &fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);

    // Generate texture
    glGenTextures(1, &textureColorbuffer);
    glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 600, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    // attach it to currently bound framebuffer object
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureColorbuffer, 0);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}


SpringVisualization::~SpringVisualization()
{
}


void SpringVisualization::Render(const SimulationResultsRepo &repo)
{
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);

    glClear(GL_COLOR_BUFFER_BIT);

    shader.Use();
    shader.SetColor(glm::vec4(1.0f));

    springMesh.Update(
        GenerateVertices(repo),
        GenerateIndices()
    );

    springMesh.Use();

    glDrawElements(GL_TRIANGLES, springMesh.GetElementsCnt(), GL_UNSIGNED_INT, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    ImGui::Begin(WindowName());

    ImGui::DragFloat("Scale", &scale);
    const ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
    ImGui::Image(reinterpret_cast<void*>(textureColorbuffer), viewportPanelSize /*ImVec2{ 0, 1 }, ImVec2{ 1, 0 }*/);

    ImGui::End();
}


std::vector<float> SpringVisualization::GenerateVertices(const SimulationResultsRepo &repo) const
{
    std::vector<float> vertices;

    const float freeEndPos = -repo.GetSpringFreeEndPositions().back();

    const float massPos = -repo.GetPosition().back();

    constexpr float yOffset = -0.2f;

    // Spring
    vertices.push_back(-0.5f-0.2f);
    vertices.push_back(freeEndPos / scale + yOffset);

    vertices.push_back(-0.5f+0.2f);
    vertices.push_back(freeEndPos / scale + yOffset);

    vertices.push_back(-0.5f+0.2f);
    vertices.push_back(massPos / scale + 0.05f + yOffset);

    vertices.push_back(-0.5f-0.2f);
    vertices.push_back(massPos / scale + 0.05f + yOffset);

    // Mass
    vertices.push_back(-0.5f-0.3f);
    vertices.push_back(massPos / scale - 0.05f + yOffset);

    vertices.push_back(-0.5f+0.3f);
    vertices.push_back(massPos / scale - 0.05f + yOffset);

    vertices.push_back(-0.5f+0.3f);
    vertices.push_back(massPos / scale + 0.05f + yOffset);

    vertices.push_back(-0.5f-0.3f);
    vertices.push_back(massPos / scale + 0.05f + yOffset);

    return vertices;
}


std::vector<unsigned int> SpringVisualization::GenerateIndices() const
{
    return {
        0, 1, 2,
        0, 2, 3,
        4, 5, 6,
        4, 6, 7
    };
}
