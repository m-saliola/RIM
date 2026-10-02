#include "vertex_buffer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
    glGenBuffers(1, &m_ID);
    SetData(data, size);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &m_ID);
}

void VertexBuffer::Bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VertexBuffer::Unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::SetData(const void* data, unsigned int size) const {
    Bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
}
