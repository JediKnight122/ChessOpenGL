#include "brickshader.h"




Brickshader::Brickshader()
{

}

void Brickshader::SetBrickSize(QVector2D vec2){

    m_sizeBrick=vec2;
}

void Brickshader::setShaderUniforms(){
    Shader::setShaderUniforms();
    this->shaderProgram()->setUniformValue("brickSize",m_sizeBrick);
}


