#ifndef FIGUR_H
#define FIGUR_H

#include <Drawable.h>
#include "Transformation.h"


class Figur
{

protected:
Drawable * m_Drawable;
Texture * m_texture;
Transformation m_Transformation;
Node * m_TransformationNode;
Node * m_Node;

public:
    Figur();
    Figur(Drawable &pDrawable);
    Drawable * GetDrawable();
    void SetTransformation(Transformation pTransformation);
    Node * GetNode();
};

#endif // FIGUR_H
