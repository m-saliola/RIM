#pragma once

#include <glad/glad.h>

#include <vector>

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int GetSizeOfType(unsigned int type) {
        switch (type) {
            case GL_FLOAT: return sizeof(float);
            case GL_UNSIGNED_INT: return sizeof(unsigned int);
            case GL_UNSIGNED_BYTE: return sizeof(unsigned char);
        }
        return 0;
    }
};

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;

public:
    VertexBufferLayout();

    template <typename T>
    void Push(unsigned int count);

    inline std::vector<VertexBufferElement> GetElements() const { return m_Elements; };
    inline unsigned int GetStride() const { return m_Stride; };
};
