#include "scenemanager.h"
#include "screenrenderer.h"
#include "mousekeyboardcameracontroller.h"
#include "simpleplane.h"
#include "shadertimed.h"
#include "transformation.h"
#include "shadermanager.h"
#include "modeltransformation.h"
#include "figur.h"
#include "bauer.h"
#include "feld.h"
#include "trianglemesh.h"
#include <QDebug>
#include "brickshader.h"
#include "color.h"
#include "draganddropper.h"

Node* initScene1();

void SceneManager::initScenes()
{
    Camera* cam = new Camera();
    CameraController* camController = new MouseKeyboardCameraController(cam);
    Q_UNUSED(camController);
    RenderingContext* myContext = new RenderingContext(cam);
    unsigned int myContextNr = SceneManager::instance()->addContext(myContext);
    unsigned int myScene = SceneManager::instance()->addScene(initScene1());
    ScreenRenderer* myRenderer = new ScreenRenderer(myContextNr, myScene);
    Q_UNUSED(myRenderer);

    // Vorsicht: Die Szene muss initialisiert sein, bevor das Fenster verändert wird (Fullscreen)
    SceneManager::instance()->setActiveScene(myScene);
    SceneManager::instance()->setActiveContext(myContextNr);
    //    SceneManager::instance()->setFullScreen();
}

Node* initScene1()
{
    QString path(SRCDIR); // aus .pro-File!

     Node* root = new Node();

#pragma region Physik
    int v_Slot = PhysicEngineManager::createNewPhysicEngineSlot(PhysicEngineName::BulletPhysicsLibrary);
    PhysicEngine* v_PhysicEngine = PhysicEngineManager::getPhysicEngineBySlot(v_Slot);



#pragma endregion

    Drawable* v_Plane = new Drawable(new SimplePlane(100.f));
    v_Plane->getProperty<Color>()->setValue(1,1,1,1);
    v_Plane->setStaticGeometry(true);
    Transformation* v_TransformationPlane = new Transformation();
    Node* transformationPlaneNode = new Node(v_TransformationPlane);
    v_TransformationPlane->rotate(-90.f, 1.f, 0.f, 0.f);
    v_TransformationPlane->translate(0,0,-5);
    PhysicObject* v_PlanePhys = v_PhysicEngine->createNewPhysicObject(v_Plane);
    PhysicObjectConstructionInfo* v_Constrinf = new PhysicObjectConstructionInfo();
    v_Constrinf->setCollisionHull(CollisionHull::BoxAABB); // Automatische generierung einer Box aus den Vertexpunkten
    v_PlanePhys->setConstructionInfo(v_Constrinf);
    v_PlanePhys->registerPhysicObject();

    // Erzeuge Idle Observer der Drag and Drop übernimmt
    new DragAndDropper(v_PhysicEngine);

    root->addChild(transformationPlaneNode);
    transformationPlaneNode->addChild(new Node(v_Plane));


    //Drawables als Vorlagen für die jeweiligen Figuren anlegen
    Drawable * bauer =new Drawable(new TriangleMesh(path +QString("/model/PAWN.obj")));
    Drawable * koenig;
    Drawable * dame;
    Drawable * laeufer;
    Drawable * pferd;
    Drawable * turm;

    Node* tempNode;

    Figur * figur = new Figur();
    Feld schachBrett[8][8] = {Feld()};
    PhysicObject* v_PhysicObjects[32];
    Transformation tempTrans;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            schachBrett[i][j].m_Transformation.translate(4* i, 0, j * 4);
            /*
            tempNode = new Node(&schachBrett[i][j].m_Transformation);
            tempNode->addChild(new Node(schachBrett[i][j].m_Drawable));
            root->addChild(tempNode);
            */
        }

    }
    Figur * weisseFiguren[16];
    Figur * schwarzeFiguren[16];

    
    Brickshader * shader = ShaderManager::getShader<Brickshader>("://shaders/brickShader.vert", "://shaders/brickShader.frag");
shader->SetBrickSize(QVector2D(0.3, 0.2));
shader->setMsecsPerIteration(16000);
shader->setShaderUniforms();
    for(int i=0; i<8; i++){

        weisseFiguren[i]=new Bauer(*new Drawable(bauer->getGeometry()), schachBrett[1][i].GetTransformation());
       // weisseFiguren[i]->SetTransformation( schachBrett[1][i].GetTransformation());
        schachBrett[1][i].SetFigur(weisseFiguren[i]);
        weisseFiguren[i]->GetDrawable()->setShader(shader);
    }
    for(int i=0; i<8; i++){
        schwarzeFiguren[i]=new Bauer(*new Drawable(bauer->getGeometry()), schachBrett[7][i].GetTransformation());
        schachBrett[7][i].SetFigur(schwarzeFiguren[i]);
    }
    

   

    
    
    //    Drawable *p2 = new Drawable(new
    //    TriangleMesh("/Users/bdr1/vorlesungen/CG/vorlesungsbeispiele/SimpleShader/monkey.obj"));
    //    Drawable *cubeModel = new Drawable(new SimpleCube());

    



for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){

        if(schachBrett[i][j].GetFigur() == nullptr) continue;


        tempNode = new Node(&schachBrett[i][j].GetFigur()->m_Transformation);
        tempNode->addChild(new Node(schachBrett[i][j].GetFigur()->GetDrawable()));
        root->addChild(tempNode);

        // Ein PhysicObject von der Engine für ein Drawable erzeugen lassen
        v_PhysicObjects[i+j] = v_PhysicEngine->createNewPhysicObject(schachBrett[i][j].GetFigur()->GetDrawable());

        // Ein PhysicObjectConstructionInfo Objekt erzeugen, welches die Eigenschaften eines PhysicObjects festlegt,
        // für jede Eigenschaft gibt es einen Standardwert, das Objekt wird später automatisch gelöscht
        PhysicObjectConstructionInfo* v_PhysicObjectConstructionInfo = new PhysicObjectConstructionInfo();
        // Optionale veränderung der Informationen
        v_PhysicObjectConstructionInfo->setCollisionHull(CollisionHull::BoxAABB); // Sphere mit einem festgelegten
                                                                                       // Radius erstellen
        v_PhysicObjectConstructionInfo->setBoxHalfExtends(QVector3D(3, 5,3));  // Radius der Sphere auf 0.5 setzen
        v_PhysicObjectConstructionInfo->setCcdActivation(true); // durchdringen durch andere Objekte Abfangen, benötigt
        v_PhysicObjectConstructionInfo->setRollingFriction(0.7f);
        v_PhysicObjectConstructionInfo->setFriction(2.7f);

        // Dem PhysicObject die Konstruktionsinformationen geben
        v_PhysicObjects[i+j]->setConstructionInfo(v_PhysicObjectConstructionInfo);

        // Das PhysicObject in seiner Engine Registrieren, damit die Simulation starten kann
        v_PhysicObjects[i+j]->registerPhysicObject();
    }

}

 qInfo() <<"Added Figures.";

    return (root);
}
