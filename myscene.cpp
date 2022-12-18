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

    //Drawables als Vorlagen für die jeweiligen Figuren anlegen
    Drawable * bauer =new Drawable(new TriangleMesh(path +QString("/model/PAWN.obj")));
    Drawable * koenig;
    Drawable * dame;
    Drawable * laeufer;
    Drawable * pferd;
    Drawable * turm;


    Node* root = new Node();

    Figur * figur = new Figur();
    Feld schachBrett[8][8] = {Feld()};

    Figur * weisseFiguren[16];
    Figur * schwarzeFiguren[16];

    Transformation tempTrans;

    for(int i=0; i<9; i++){
        weisseFiguren[i]=new Bauer(*bauer);
        tempTrans.translate(i,0,0);
        weisseFiguren[i]->SetTransformation(tempTrans);
    }
    for(int i=0; i<9; i++){
        schwarzeFiguren[i]=new Bauer(*bauer);
    }



    schachBrett[0][0].SetFigur(figur);

   qInfo() <<"Hallo?!?" <<weisseFiguren[0]->GetNode();

root->addChild(weisseFiguren[0]->GetNode());
root->addChild(weisseFiguren[1]->GetNode());

    //    Drawable *p2 = new Drawable(new
    //    TriangleMesh("/Users/bdr1/vorlesungen/CG/vorlesungsbeispiele/SimpleShader/monkey.obj"));
    //    Drawable *cubeModel = new Drawable(new SimpleCube());




    return (root);
}
