#include "index_buffer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) : m_Count(count) {
    glGenBuffers(1, &m_ID);
    SetData(data, count);
}

IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &m_ID);
}

void IndexBuffer::Bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void IndexBuffer::Unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::SetData(const void* data, unsigned int count) const {
    m_Count = count;
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_DYNAMIC_DRAW);
}
