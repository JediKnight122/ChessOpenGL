#ifndef FELD_H
#define FELD_H
#include "figur.h"
#include "transformation.h"
#include "simpleplane.h"

class Feld
{
public:
    Feld();

    Feld(Transformation pTransformation);
    Transformation m_Transformation;

    Drawable* m_Drawable;
    Texture* m_texture;

Figur* GetFigur();
void SetFigur(Figur* pFigur);
Transformation GetTransformation();

private:
    Figur * m_Figur=nullptr;
    
};

#endif // FELD_H
