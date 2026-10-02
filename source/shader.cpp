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

    Bind();
}

Shader::~Shader() {
    glDeleteProgram(m_ID);
}

void Shader::Bind() const {
    if (m_BoundID != m_ID) {
        glUseProgram(m_ID);
        m_BoundID = m_ID;
    }
}

void Shader::Unbind() const {
    glUseProgram(0);
    m_BoundID = 0;
}

unsigned int Shader::GetUniformLocation(const std::string &name) {
    return glGetUniformLocation(m_ID, name.c_str());
}
