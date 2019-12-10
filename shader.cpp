//
// Created by leticia on 10/12/18.
//

#include "shader.h"
#include <iostream>
#include <fstream>


//glm::vec3 lightPos( 1.2f, 2.0f, 2.0f );

Shader::Shader(const std::string& fileName)
{
    m_program = glCreateProgram();
    m_shaders[0] = CreateShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER);
    m_shaders[1] = CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

    for(unsigned int i = 0; i < NUM_SHADERS; i++)
        glAttachShader(m_program, m_shaders[i]);

    glBindAttribLocation(m_program, 0, "position");
    glBindAttribLocation(m_program, 1, "texCoord");
    glBindAttribLocation(m_program, 2, "normal");

    glLinkProgram(m_program);
    CheckShaderError(m_program, GL_LINK_STATUS, true, "Error linking shader program");

    glValidateProgram(m_program);
    CheckShaderError(m_program, GL_LINK_STATUS, true, "Invalid shader program");

    m_uniforms[0] = glGetUniformLocation(m_program, "MVP");
    m_uniforms[1] = glGetUniformLocation(m_program, "Normal");
    m_uniforms[2] = glGetUniformLocation(m_program, "lightDirection");

    m_uniforms[3] = glGetUniformLocation(m_program, "material.diffuse");
    m_uniforms[4] = glGetUniformLocation(m_program, "material.specular");

    m_uniforms[5] = glGetUniformLocation(m_program, "light.position");
    m_uniforms[6] = glGetUniformLocation(m_program, "light.direction");
    m_uniforms[7] = glGetUniformLocation(m_program, "viewPos");

    m_uniforms[8] = glGetUniformLocation(m_program, "light.ambient");
    m_uniforms[9] = glGetUniformLocation(m_program, "light.diffuse");
    m_uniforms[10] = glGetUniformLocation(m_program, "light.specular");

    m_uniforms[11] = glGetUniformLocation(m_program, "light.constant");
    m_uniforms[12] = glGetUniformLocation(m_program, "light.linear");
    m_uniforms[13] = glGetUniformLocation(m_program, "light.quadratic");

    m_uniforms[14] = glGetUniformLocation(m_program, "material.shininess");
}

Shader::~Shader()
{
    for(unsigned int i = 0; i < NUM_SHADERS; i++)
    {
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }

    glDeleteProgram(m_program);
}

void Shader::Bind()
{
    glUseProgram(m_program);
}

void Shader::Update(const Transform& transform, const Camera& camera)
{
    glm::mat4 MVP = transform.GetMVP(camera);
    glm::mat4 Normal = transform.GetModel();

    glUniformMatrix4fv(m_uniforms[0], 1, GL_FALSE, &MVP[0][0]);
    glUniformMatrix4fv(m_uniforms[1], 1, GL_FALSE, &Normal[0][0]);
    // altera direção da luz
    glUniform3f(m_uniforms[2], 1.0f, 0.0f, 1.0f);
    
    glUniform1i(m_uniforms[3], 0 );
    glUniform1i(m_uniforms[4], 1 );
    //lightPos.x, lightPos.y, lightPos.z
    glUniform3f(m_uniforms[5], 1.2f, 2.0f, 2.0f); 
    glUniform3f( m_uniforms[6], -0.2f, -1.0f, -0.3f );
    //glUniform3f( m_uniforms[7],  camera.GetPosition( ).x, camera.GetPosition( ).y, camera.GetPosition( ).z );
    glUniform3f( m_uniforms[7],  3.5f, 0.0f, -2.0f );

    // Set lights properties
    glUniform3f( m_uniforms[8],  0.3f, 0.5f, 0.3f );
    glUniform3f( m_uniforms[9],  0.5f, 1.5f, 0.5f );
    glUniform3f( m_uniforms[10], 1.0f, 3.0f, 1.0f );
    glUniform1f( m_uniforms[11], 1.0f );
    glUniform1f( m_uniforms[12], 0.09 );
    glUniform1f(m_uniforms[13], 0.032 );

    // Set material properties
    glUniform1f( m_uniforms[14], 32.0f );
}

std::string Shader::LoadShader(const std::string& fileName)
{
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
            output.append(line + "\n");
        }
    }
    else
    {
        std::cerr << "Unable to load shader: " << fileName << std::endl;
    }

    return output;
}

void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}

GLuint Shader::CreateShader(const std::string& text, unsigned int type)
{
    GLuint shader = glCreateShader(type);

    if(shader == 0)
        std::cerr << "Error compiling shader type " << type << std::endl;

    const GLchar* p[1];
    p[0] = text.c_str();
    GLint lengths[1];
    lengths[0] = text.length();

    glShaderSource(shader, 1, p, lengths);
    glCompileShader(shader);

    CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error compiling shader!");

    return shader;
}