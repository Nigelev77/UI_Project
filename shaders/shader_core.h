#pragma once


typedef unsigned int GLuint;

enum ShaderType
{
    SHADER_VERT = (1<<0),
    SHADER_FRAG = (1<<2),
    SHADER_GEO = (1<<3),
    SHADER_TESS = (1<<4),
    SHADER_COMP = (1<<5),
    SHADER_INVALID = (1<<31),
};


// TODO: add some sort of better pipeline to share vertex/frag progs
struct Shader
{
    GLuint progID, vertID, fragID;
    int type;
};

Shader CreateShader(char* name);
void LoadShader(GLuint prog);
void UnloadShader(GLuint prog);

