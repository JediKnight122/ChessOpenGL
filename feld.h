#ifndef FELD_H
#define FELD_H
#include "figur.h"
#include "transformation.h"

class Feld
{
public:
    Feld();
    Feld(Transformation pTransformation);

Figur* GetFigur();
void SetFigur(Figur* pFigur);
Transformation GetTransformation();

private:
    Figur * m_Figur=nullptr;
    Transformation m_Transformation;
};

#endif // FELD_H
