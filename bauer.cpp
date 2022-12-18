#include "bauer.h"

Bauer::Bauer()
{

}

Bauer::Bauer(Drawable &pDrawable) : Figur(pDrawable){

}

Drawable * Figur::GetDrawable(){
    return m_Drawable;
}
