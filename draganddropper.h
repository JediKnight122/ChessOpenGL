#ifndef DRAGANDDROPPER_H
#define DRAGANDDROPPER_H

#include "idleobserver.h"

class PhysicEngine;

class DragAndDropper : public IdleObserver
{
public:
    DragAndDropper(PhysicEngine* physicEngine);
    virtual void doIt();

private:
    PhysicEngine* m_PhysicEngine;
};

#endif // DRAGANDDROPPER_H
