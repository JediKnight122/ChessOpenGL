#include "feld.h"

Feld::Feld()
{
    m_Drawable = new Drawable( new SimplePlane(1, 0, 1));
}

Feld::Feld(Transformation pTransformation){
    m_Drawable = new Drawable(new SimplePlane(1, 0, 1));
    m_Transformation=pTransformation;
}
Figur * Feld::GetFigur(){
    return m_Figur;
}

void Feld::SetFigur(Figur * pFigur){
    m_Figur=pFigur;
    m_Figur->SetTransformation(m_Transformation);
}

Transformation Feld::GetTransformation(){
    return m_Transformation;
}
