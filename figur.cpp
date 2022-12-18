#include "figur.h"

Figur::Figur()
{

}

Figur::Figur(Drawable &pDrawable){
m_Drawable= &pDrawable;
m_TransformationNode = new Node(&m_Transformation);
m_Node = new Node(*m_TransformationNode);
}

void Figur::SetTransformation(Transformation pTransformation){
    m_Transformation=pTransformation;
}

Node* Figur::GetNode(){
    return m_Node;
}
