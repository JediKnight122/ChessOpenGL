#include "bauer.h"

Bauer::Bauer()
{

}

Bauer::Bauer(Drawable &pDrawable, Transformation pTransformation) : Figur(pDrawable, pTransformation){

}

Drawable * Figur::GetDrawable(){
    return m_Drawable;
}
