//
// Created by leticia on 10/12/18.
//

#ifndef CG_2018_2_OPENGL_TEXTURE_H
#define CG_2018_2_OPENGL_TEXTURE_H

#include <string>
#include <GL/glew.h>

class Texture
{
public:

    Texture(const std::string& fileName);

    void Bind();

    virtual ~Texture();

protected:
private:
    Texture(const Texture& texture) {}
    void operator=(const Texture& texture) {}

    GLuint m_texture;
};

#endif //CG_2018_2_OPENGL_TEXTURE_H
