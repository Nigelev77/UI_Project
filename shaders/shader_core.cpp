#include "shader_core.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>



static bool Compile(GLuint shader)
{
    glCompileShader(shader);
    GLint status;
    if(glGetShaderiv(shader, GL_COMPILE_STATUS, &status); !status)
    {
        char infoLog[1024];
        glGetShaderInfoLog(shader, sizeof(infoLog), NULL, infoLog);
        std::cout<<infoLog<<'\n';
    }
    return status;
}


Shader CreateShader(char* name)
{
    //TODO: do some file searching for multiple shader programs (e.g. comp/tesselation/geo)
    //so no need to pass types
    GLuint prog, vert, frag;
    
    prog = glCreateProgram();
    vert = glCreateShader(GL_VERTEX_SHADER);
    frag = glCreateShader(GL_FRAGMENT_SHADER);
    
    

    std::stringstream src;
    std::ifstream file;
    

    {// vert
        
        file.open(strcat(name, ".vert"));
        src << file.rdbuf();
        file.close();
        
        const std::string& srcStr = src.str();
        const char* cSrcStr = srcStr.c_str();
        glShaderSource(vert, srcStr.length(), &cSrcStr, NULL);
        int success = Compile(vert);
        if(!success)
        {
            return {UINT32_MAX, UINT32_MAX, UINT32_MAX, (1<<31)};
        }
    }

    {//frag 
        file.open(strcat(name, ".frag"));
        src << file.rdbuf();
        file.close();

        const std::string& srcStr = src.str();
        const char* cSrcStr = srcStr.c_str();
        glShaderSource(frag, srcStr.length(), &cSrcStr, NULL);
        int success = Compile(frag);
        if(!success)
        {
            return {UINT32_MAX, UINT32_MAX, UINT32_MAX, (1<<31)};
        }
    }


    glAttachShader(prog, vert);
    glAttachShader(prog, frag);
    glLinkProgram(prog); 

    return {prog, vert, frag, SHADER_VERT | SHADER_FRAG};
}



void LoadShader(GLuint prog)
{
    glUseProgram(prog);
}


void UnloadShader(GLuint prog)
{
    glUseProgram(0); 
    //NOTE: Potentially undefined
}