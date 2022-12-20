#ifndef FIGUR_H
#define FIGUR_H

#include <Drawable.h>
#include "Transformation.h"


class Figur
{
public:
    Transformation m_Transformation;
protected:
Drawable * m_Drawable;
Texture * m_texture;

Node * m_TransformationNode;
Node * m_Node;

public:
    Figur();
    Figur(Drawable &pDrawable, Transformation pTransformation);
    Drawable * GetDrawable();
    void SetTransformation(Transformation pTransformation);
    Node * GetNode();
};

#endif // FIGUR_H
