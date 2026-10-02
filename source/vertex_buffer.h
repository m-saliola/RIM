#pragma once

#include <glad/glad.h>

class VertexBuffer {
private:
    unsigned int m_ID;

public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    VertexBuffer(const VertexBuffer&) = delete;
    VertexBuffer& operator=(const VertexBuffer&) = delete;

    void Bind() const;
    void Unbind() const;

    void SetData(const void* data, unsigned int size) const;
};
