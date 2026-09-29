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

    void SetBool(const std::string &name, bool value) const;
    void SetInt(const std::string &name, int value) const;
    void SetFloat(const std::string &name, float value) const;

    inline unsigned int GetID() const { return m_ID; }

    static inline unsigned int GetBoundID() { return m_BoundID; }
};
