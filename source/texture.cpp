#include "texture.h"

unsigned int Texture::m_BoundID = 0;

Texture::Texture(const std::string& path) : m_Path(path) {
    stbi_set_flip_vertically_on_load(true);
    m_Data = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 0);

    glGenTextures(1, &m_ID);
    glBindTexture(GL_TEXTURE_2D, m_ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_Data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(m_Data);
}

Texture::~Texture() {
    glDeleteTextures(1, &m_ID);
}

void Texture::Bind(unsigned int slot) const {
    if (m_BoundID != m_ID) {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, m_ID);
        m_BoundID = m_ID;
    }
}

void Texture::Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
    m_BoundID = 0;
}

