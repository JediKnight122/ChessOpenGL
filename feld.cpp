#include "feld.h"

Feld::Feld()
{

}

Feld::Feld(Transformation pTransformation){
    m_Transformation=pTransformation;
}
Figur * Feld::GetFigur(){
    return m_Figur;
}

void Feld::SetFigur(Figur * pFigur){
    m_Figur=pFigur;
    m_Figur->SetTransformation(m_Transformation);
}
