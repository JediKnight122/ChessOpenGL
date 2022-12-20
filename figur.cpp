#include "figur.h"

Figur::Figur()
{
    m_Transformation = Transformation();
}

Figur::Figur(Drawable &pDrawable, Transformation pTransformation){

	m_Transformation = pTransformation;

m_Drawable= &pDrawable;
m_TransformationNode = new Node(&m_Transformation);
m_TransformationNode->addChild(m_Node);
m_Node = new Node();
m_Node->addChild(new Node(m_Drawable));
}

void Figur::SetTransformation(Transformation pTransformation){
    m_Transformation=pTransformation;
}

Node* Figur::GetNode(){
    return m_TransformationNode;
}
