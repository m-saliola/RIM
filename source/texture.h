#pragma once

#include <glad/glad.h>

#include <string>

#include "vendor/stb_image.h"

class Texture {
private:
    unsigned int m_ID;
    static unsigned int m_BoundID;

    std::string m_Path;
    unsigned char* m_Data;
    int m_Width, m_Height, m_BPP;

public:
    Texture(const std::string& path);
    ~Texture();

    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;

    void Bind(unsigned int slot = 0) const;
    void Unbind() const;

    inline unsigned int GetID() const { return m_ID; }

    static inline unsigned int GetBoundID() { return m_BoundID; }

    inline int GetWidth() const { return m_Width; };
    inline int GetHeight() const { return m_Height; };
};
