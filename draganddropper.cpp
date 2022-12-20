#include "draganddropper.h"

#include "inputregistry.h"
#include "scenemanager.h"
#include "physics.h"

#include <QDebug>

DragAndDropper::DragAndDropper(PhysicEngine* physicEngine) : IdleObserver()
{
    m_PhysicEngine = physicEngine; // Pointer auf PhysicEngine abspeichern da wir später noch methoden davon benötigen
}

void DragAndDropper::doIt()
{
    MouseInput* mouseIn = InputRegistry::getInstance().getMouseInput();

    if (mouseIn->isMouseButtonPressed(Qt::LeftButton))
    {
        QVector3D v_RayDirection = mouseIn->getRayFromMousePosition(); // Der Richtungsvektor auf welchen der Cursor
                                                                       // in der Szene zeigt in Weltkoordinaten
        QVector3D lPosition = SceneManager::instance()->getActiveContext()->getCamera()->getPosition(); // Position der Kamera in
        // Weltkoordinaten

        PhysicObject* v_PhysicObject = m_PhysicEngine->rayTestClosestBody(lPosition, lPosition + 100 * v_RayDirection); // Finde das am nähesten liegende PhysicObject heraus, welches den Strahl zwischen Start und Endposition schneidet

        if (v_PhysicObject != 0) // Falls kein PhysicObject gefunden worden ist steht der NULL Pointer hier
        {
            if (v_PhysicObject->getPhysicState() == PhysicState::Dynamic)
            {
                // Falls es sich um ein dynamisches PhysicObject handelt soll es verschoben werden können, es wird
                // verhindert das wir den boden verschieben
                QMatrix4x4 v_Matrix = v_PhysicObject->getEngineModelMatrix(); // Matrix aus der PhysicEngine holen,
                // welche wir manipulieren wollen
                v_Matrix.setColumn(3, (lPosition + 10 * v_RayDirection).toVector4D()); // Die letzte Spalte
                // setzen mit dem Abstand
                // von 10 Einheiten
                // unserer Kameraposition
                // Hinweis: Die Objekte werden also in einem kreisförmigen Abstand um die aktuelle Kameraposition bewegt.
                v_PhysicObject->setEngineModelMatrix(v_Matrix); // Manipulierte Matrix wieder der PhysicEngine übergeben
                v_PhysicObject->setLinearVelocity(QVector3D(0.f, 0.f, 0.f)); // Die Geschwindigkeit des PhysicObjects
                // auf Null setzen da das Objekt sonst
                // immer weiter beschleunigt
            }
        }
    }
}
