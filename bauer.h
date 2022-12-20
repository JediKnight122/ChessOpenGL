#ifndef BAUER_H
#define BAUER_H
#include "figur.h"

class Bauer: public Figur
{
public:
    Bauer();
    Bauer(Drawable &pDrawable, Transformation pTransformation);
};

#endif // BAUER_H
