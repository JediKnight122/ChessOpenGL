#ifndef BRICKSHADER_H
#define BRICKSHADER_H
#include "shadertimed.h"

class Brickshader: public ShaderTimed
{
public:
    Brickshader();
    virtual void setShaderUniforms() override;
    void SetBrickSize(QVector2D vec2);

private:
    QVector2D m_sizeBrick;
};

#endif // BRICKSHADER_H
