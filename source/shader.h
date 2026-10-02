#pragma once

#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
private:
    unsigned int m_ID;
    static unsigned int m_BoundID;

public:
    Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
    ~Shader();

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    void Bind() const;
    void Unbind() const;

    unsigned int GetUniformLocation(const std::string &name);

    inline unsigned int GetID() const { return m_ID; }

    static inline unsigned int GetBoundID() { return m_BoundID; }
};
