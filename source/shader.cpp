#include "shader.h"

unsigned int Shader::m_BoundID = 0;

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath) {
    std::string vertexShaderSourceStr, fragmentShaderSourceStr;
    std::ifstream vertexShaderFile, fragmentShaderFile;

    vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        vertexShaderFile.open(vertexShaderPath);
        fragmentShaderFile.open(fragmentShaderPath);

        std::stringstream vertexShaderStream, fragmentShaderStream;

        vertexShaderStream << vertexShaderFile.rdbuf();
        fragmentShaderStream << fragmentShaderFile.rdbuf();

        vertexShaderFile.close();
        fragmentShaderFile.close();

        vertexShaderSourceStr = vertexShaderStream.str();
        fragmentShaderSourceStr = fragmentShaderStream.str();
    } catch (std::ifstream::failure e) {
        std::cout << "Shader file reading failed" << std::endl;
    }

    const char* vertexShaderSource = vertexShaderSourceStr.c_str();
    const char* fragmentShaderSource = fragmentShaderSourceStr.c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    m_ID = glCreateProgram();
    glAttachShader(m_ID, vertexShader);
    glAttachShader(m_ID, fragmentShader);
    glLinkProgram(m_ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader() {
    glDeleteProgram(m_ID);
}

void Shader::Bind() {
    if (m_BoundID != m_ID) {
        glUseProgram(m_ID);
        m_BoundID = m_ID;
    }
}

void Shader::Unbind() {
    glUseProgram(0);
    m_BoundID = 0;
}

void Shader::SetBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(m_ID, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(m_ID, name.c_str()), value);
}

void Shader::SetFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(m_ID, name.c_str()), value);
}
