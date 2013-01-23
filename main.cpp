#include "header.h"
#include "RubicCube.h"
#include "RubicElt.h"

using namespace irr;
using namespace video;
using namespace core;
using namespace scene;

using namespace rubic;

class MyEventReceiver : public IEventReceiver {

    public:
        struct SMouseState{
                core::position2di Position;
                bool LeftButtonDown;
                bool RightButtonDown;
                bool MiddleButtonDown;
                SMouseState() : LeftButtonDown(false), RightButtonDown(false), MiddleButtonDown(false) { }
        } MouseState;

        virtual bool OnEvent(const SEvent& event){
            if(event.EventType == EET_MOUSE_INPUT_EVENT){
                switch(event.MouseInput.Event){
                    case EMIE_LMOUSE_PRESSED_DOWN:
                        MouseState.LeftButtonDown = true;
                        break;
                    case EMIE_LMOUSE_LEFT_UP:
                        MouseState.LeftButtonDown = false;
                        break;
                    case EMIE_RMOUSE_PRESSED_DOWN:
                        MouseState.RightButtonDown = true;
                        break;
                    case EMIE_RMOUSE_LEFT_UP:
                        MouseState.RightButtonDown = false;
                        break;
                    case EMIE_MMOUSE_LEFT_UP:
                        MouseState.MiddleButtonDown = true;
                        break;
                    case EMIE_MMOUSE_PRESSED_DOWN:
                        MouseState.MiddleButtonDown = false;
                        break;
                }
                return false;
            }
        }

        const SMouseState &GetMouseState(void) const{
            return MouseState;
        }
};


int main(void){
    MyEventReceiver receiver;

    //Device, driver et graphe de scene
    irr::IrrlichtDevice* device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(800, 600), 32, false, false, false, &receiver);
    irr::video::IVideoDriver* driver = device->getVideoDriver();
        /*irr::video::SMaterial material;
        material.FrontfaceCulling = true;
        driver->setMaterial(material);*/
    irr::scene::ISceneManager *sceneManager = device->getSceneManager();

    //On rend invisible le curseur
    //device->getCursorControl()->setVisible(false);


    RubicCube *cube = new RubicCube(sceneManager);


    irr::scene::IMeshSceneNode *c_centre = sceneManager->addCubeSceneNode(BLOC_S, 0, 33, irr::core::vector3df(0, 0, 0));
    c_centre->setMaterialType(irr::video::EMT_SOLID);
    c_centre->setMaterialTexture(0, driver->getTexture("E:\\Codage\\Rubirrks\\Ressources\\blue.jpg"));

    irr::scene::IMeshSceneNode *c_up = sceneManager->addCubeSceneNode(BLOC_S, 0, 34, irr::core::vector3df(-(BLOC_S+BLOC_SPC), 0, 0));
    c_up->setMaterialType(irr::video::EMT_SOLID);
    c_up->setMaterialTexture(0, driver->getTexture("E:\\Codage\\Rubirrks\\Ressources\\red.jpg"));

    irr::scene::IMeshSceneNode *c_down = sceneManager->addCubeSceneNode(BLOC_S, 0, 35, irr::core::vector3df(BLOC_S+BLOC_SPC, 0, 0));
    c_down->setMaterialType(irr::video::EMT_SOLID);
    c_down->setMaterialTexture(0, driver->getTexture("E:\\Codage\\Rubirrks\\Ressources\\red.jpg"));

    irr::scene::IMeshSceneNode *c_north = sceneManager->addCubeSceneNode(BLOC_S, 0, 36, irr::core::vector3df(0, BLOC_S+BLOC_SPC, 0));
    c_north->setMaterialType(irr::video::EMT_SOLID);
    c_north->setMaterialTexture(0, driver->getTexture("E:\\Codage\\Rubirrks\\Ressources\\red.jpg"));

    irr::scene::IMeshSceneNode *c_south = sceneManager->addCubeSceneNode(BLOC_S, 0, 37, irr::core::vector3df(0, -(BLOC_S+BLOC_SPC), 0));
    c_south->setMaterialType(irr::video::EMT_SOLID);
    c_south->setMaterialTexture(0, driver->getTexture("E:\\Codage\\Rubirrks\\Ressources\\red.jpg"));

    irr::scene::IMeshSceneNode *c_east = sceneManager->addCubeSceneNode(BLOC_S, 0, 38, irr::core::vector3df(0, 0, BLOC_S+BLOC_SPC));
    c_east->setMaterialType(irr::video::EMT_SOLID);
    c_east->setMaterialTexture(0, driver->getTexture("E:\\Codage\\Rubirrks\\Ressources\\red.jpg"));

    irr::scene::IMeshSceneNode *c_west = sceneManager->addCubeSceneNode(BLOC_S, 0, 39, irr::core::vector3df(0, 0, -(BLOC_S+BLOC_SPC)));
    c_west->setMaterialType(irr::video::EMT_SOLID);
    c_west->setMaterialTexture(0, driver->getTexture("E:\\Codage\\Rubirrks\\Ressources\\red.jpg"));

    irr::scene::IMeshSceneNode *c_111 = sceneManager->addCubeSceneNode(BLOC_S, c_down, 40, irr::core::vector3df(0, -(BLOC_S+BLOC_SPC), -(BLOC_S+BLOC_SPC)));
    c_111->setMaterialType(irr::video::EMT_SOLID);
    c_111->setMaterialTexture(0, driver->getTexture("E:\\Codage\\Rubirrks\\Ressources\\blue.jpg"));

    irr::scene::IMeshSceneNode *c_121 = sceneManager->addCubeSceneNode(BLOC_S, c_down, 41, irr::core::vector3df(0, -(BLOC_S+BLOC_SPC), 0));
    c_121->setMaterialType(irr::video::EMT_SOLID);
    c_121->setMaterialTexture(0, driver->getTexture("E:\\Codage\\Rubirrks\\Ressources\\blue.jpg"));

    irr::scene::IMeshSceneNode *c_131 = sceneManager->addCubeSceneNode(BLOC_S, c_down, 42, irr::core::vector3df(0, -(BLOC_S+BLOC_SPC), BLOC_S+BLOC_SPC));
    c_131->setMaterialType(irr::video::EMT_SOLID);
    c_131->setMaterialTexture(0, driver->getTexture("E:\\Codage\\Rubirrks\\Ressources\\blue.jpg"));

    /*irr::scene::IMesh *cubeMesh = sceneManager->getMesh("E:\\Codage\\Rubirrks\\Ressources\\cube.irrmesh");
    irr::scene::IMeshSceneNode *c_test = sceneManager->addMeshSceneNode(cubeMesh, 0, 99, irr::core::vector3df(0, 100, 100));

    IMesh *cubedMesh = sceneManager->getMesh("E:\\Codage\\Rubirrks\\cube.irrmesh");
    IMeshSceneNode *meshtest = sceneManager->addOctTreeSceneNode(cubedMesh, 0, 888);
        meshtest->setPosition(vector3df(0, 200, 0));
    */



    //sceneManager->setAmbientLight(irr::video::SColorf(1.0, 1.0, 1.0, 0.0));

    irr::scene::ICameraSceneNode *camera;
    camera = sceneManager->addCameraSceneNodeMaya(0, 100.0f, 200.0f, 2000.0f, 77);
    //camera = sceneManager->addCameraSceneNode(cube->getRubicElt(1, 1, 1)->anode, vector3df(100, 0, 0), vector3df(0, 0, 50));

    ISceneCollisionManager *colisionManager = sceneManager->getSceneCollisionManager();
        //ISceneNode *node = cube->getRubicElt(2, 2, 2)->node;
        //IAnimatedMeshSceneNode *node = cube->getRubicElt(2, 2, 2)->anode;

    //scene::ITriangleSelector* selector = 0;
    //selector = sceneManager->createTriangleSelector(node);
    //selector = sceneManager->createTriangleSelectorFromBoundingBox(node);
    //   node->setTriangleSelector(selector);
    //selector->drop();


    //La chaine pour le titre de la fenetre
    irr::core::vector3df posCam;
    core::position2d<s32> posCursor = device->getCursorControl()->getPosition();

/*** essay gestion colision mouse cube ***/
    irr::core::line3d<float> collRay;
	collRay = colisionManager->getRayFromScreenCoordinates(posCursor, sceneManager->getActiveCamera());

    // get the collision
	core::vector3df collPoint;
	core::triangle3df collTriangle;
	IAnimatedMeshSceneNode *node = 0;
	const scene::ISceneNode* pNode = 0;

	//pNode = colisionManager->getSceneNodeAndCollisionPointFromRay(collRay, collPoint, collTriangle);
/****************************************/

    wchar_t titre[100];
    bool hasCollision = false;
    int i = 0;

    //La boucle de rendu
    while(device->run()){

        posCam = camera->getPosition();
        posCursor = device->getCursorControl()->getPosition();
        swprintf(titre, 100, L"FPS : %d (mode debug) |  PosCam :  "
        "X : %f Y : %f Z : %f, m.X : %ld m.Y : %ld", driver->getFPS(), posCam.X, posCam.Y, posCam.Z, posCursor.X, posCursor.Y);
        device->setWindowCaption(titre);


        collRay = colisionManager->getRayFromScreenCoordinates(posCursor, sceneManager->getActiveCamera());
        vector3df ppp; triangle3df ttt;
        ISceneNode *test = 0;
        test = colisionManager->getSceneNodeAndCollisionPointFromRay(collRay, ppp, ttt);
    int face = 0;


        for(int i = 0; i < 3; i++){
            if(hasCollision) break;
            for(int j = 0; j < 3; j++){
                if(hasCollision) break;
                for(int k = 0; k < 3; k++){
                    if(hasCollision) break;
                    node = cube->getRubicElt(i, j, k)->anode;
                    //hasCollision = colisionManager->getCollisionPoint(collRay, node->getTriangleSelector(), collPoint, collTriangle, pNode);

                    if(test){
                        if(node->getID() == test->getID()){
                            hasCollision = true;
                            //fprintf(stdout, "colision->ID: %d\n", test->getID());
                            //cube->getRubicElt(i, j, k)->anode->setMaterialFlag(video::EMF_WIREFRAME, receiver.GetMouseState().RightButtonDown);
                            node->setMaterialFlag(video::EMF_WIREFRAME, receiver.GetMouseState().RightButtonDown);
                            //fprintf(stdout, "x, y, z (%f, %f, %f)\n", ppp.X, ppp.Y, ppp.Z);
                            face = cube->getRubicElt(i, j, k)->faceIsOnPoint(ppp);
                            fprintf(stdout, "Face: %d\n", face);
                        }
                    }


                    /*if(hasCollision && pNode->isTrulyVisible() && !sceneManager->isCulled(pNode)){
                        //fprintf(stdout, "ID : %ld\n", pNode->getID());
                        fprintf(stdout, "collPoint.X : %f, collPoint.Y : %f, collPoint.Z : %f\n,", collPoint.X, collPoint.Y, collPoint.Z);
                        //hasCollision = false;
                        //pNode->setMaterialFlag(video::EMF_LIGHTING, receiver.GetMouseState().LeftButtonDown);
                        cube->getRubicElt(i, j, k)->anode->setMaterialFlag(video::EMF_WIREFRAME, receiver.GetMouseState().RightButtonDown);
                        //cube->getRubicElt(i, j, k)->anode->setMaterialFlag(video::EMF_LIGHTING, receiver.GetMouseState().RightButtonDown);

                        //cube->rotate(cube->getRubicElt(1, 1, 1), vector3df(0, 0, 0));
                    }*/
                }
            }
        }
        hasCollision = false;

        //collRay = colisionManager->getRayFromScreenCoordinates(posCursor, sceneManager->getActiveCamera());
        //oui = colisionManager->getCollisionPoint(collRay, node->getTriangleSelector(), collPoint, collTriangle, pNode);

        //if(oui){
        //    //printf("YYYYYYYEEEEEEAAAAAAHHHHHH\n\n");
        //    fprintf(stdout, "ID : %ld\n", pNode->getID());
        //    oui = false;
        //}


//printf("posCur.X : %ld, posCur.Y : %ld,, posNode.X : %ld, posNode.Y : %ld\n", posCursor.X, posCursor.Y, posNode.X, posNode.Y);

        driver->beginScene(true, true, irr::video::SColor(0, 50, 70, 50));
//c_down->setRotation(irr::core::vector3df(i*2.f, 0, 0));

        i++;

        sceneManager->drawAll();
        driver->endScene ();

        device->sleep(20);
    }

    device->drop();
    return 0;
}

