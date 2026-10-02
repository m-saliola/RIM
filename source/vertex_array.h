#pragma once

#include "vertex_buffer.h"

class VertexBufferLayout;

class VertexArray {
private:
    unsigned int m_ID;

public:

    VertexArray();
    ~VertexArray();

    VertexArray(const VertexArray&) = delete;
    VertexArray& operator=(const VertexArray&) = delete;

    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

    void Bind() const;
    void Unbind() const;
};
