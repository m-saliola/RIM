#pragma once

#include <glad/glad.h>

class IndexBuffer {
private:
    unsigned int m_ID;
    mutable unsigned int m_Count;

public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    IndexBuffer(const IndexBuffer&) = delete;
    IndexBuffer& operator=(const IndexBuffer&) = delete;

    void Bind() const;
    void Unbind() const;

    inline unsigned int GetCount() const { return m_Count; }

    void SetData(const void* data, unsigned int count) const;
};
