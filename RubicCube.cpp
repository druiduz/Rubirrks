#include "RubicCube.h"
#include "RubicElt.h"
#include "Matrix3D.h"

namespace rubic{

    irr::core::vector3df RubicCube::CubeInitPosition(0, 0, 100);

    RubicCube::RubicCube(ISceneManager *scene){
        this->sceneManager = scene;
        m = new Matrix3D(3);

        generateRubicCube();
    }

    void RubicCube::generateRubicCube(){

        IMesh *cubeMesh = sceneManager->getMesh("E:\\Codage\\Rubirrks\\Ressources\\cube.irrmesh");
        //IMesh *blackCubeMesh = sceneManager->getMesh("E:\\Codage\\Rubirrks\\cubenoir.irrmesh");
        IAnimatedMesh *blackCubeMesh = sceneManager->getMesh("E:\\Codage\\Rubirrks\\Ressources\\cubeNoir.irrmesh");
        //IMesh *cube2CubeMesh = sceneManager->getMesh("E:\\Codage\\Rubirrks\\cube2.irrmesh");
        IAnimatedMesh *cube2CubeMesh = sceneManager->getMesh("E:\\Codage\\Rubirrks\\Ressources\\cube3.irrmesh");

        scene::ITriangleSelector* selector = 0;
            //selector = sceneManager->createTriangleSelector(c);
            //c->setTriangleSelector(selector);


        /* Bloc du intérieurs */
        /*IAnimatedMeshSceneNode *c_c = sceneManager->addAnimatedMeshSceneNode(blackCubeMesh, 0, 100, vector3df(0, 0, CubeInitPosition));
            selector = sceneManager->createTriangleSelector(c_c);
            c_c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c_c), 1, 1, 1), 1, 1, 1);

        IAnimatedMeshSceneNode *c = sceneManager->addAnimatedMeshSceneNode(blackCubeMesh, 0, 101, vector3df(0, 0, CubeInitPosition+RubicElt::cube_size+RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 1, 1, 2);

        c = sceneManager->addAnimatedMeshSceneNode(blackCubeMesh, 0, 102, vector3df(0, 0, CubeInitPosition-RubicElt::cube_size-RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 1, 1, 0);

        c = sceneManager->addAnimatedMeshSceneNode(blackCubeMesh, c_c, 103, vector3df(-RubicElt::cube_size-RubicElt::cube_margin, 0, CubeInitPosition));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 2, 1, 1);

        c = sceneManager->addAnimatedMeshSceneNode(blackCubeMesh, 0, 104, vector3df(+RubicElt::cube_size+RubicElt::cube_margin, 0, CubeInitPosition));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 0, 1, 1);

        c = sceneManager->addAnimatedMeshSceneNode(blackCubeMesh, 0, 105, vector3df(0, -RubicElt::cube_size-RubicElt::cube_margin, CubeInitPosition));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 1, 0, 1);

        c = sceneManager->addAnimatedMeshSceneNode(blackCubeMesh, 0, 106, vector3df(0, +RubicElt::cube_size+RubicElt::cube_margin, CubeInitPosition));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 1, 2, 1);
*/
    /*** Bloc exterieurs ***/

        /**Face backward **/
        /*c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 107, vector3df(-RubicElt::cube_size-RubicElt::cube_margin, -RubicElt::cube_size-RubicElt::cube_margin, CubeInitPosition-RubicElt::cube_size-RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 0, 0, 0);
        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 108, vector3df(-RubicElt::cube_size-RubicElt::cube_margin, -RubicElt::cube_size-RubicElt::cube_margin, CubeInitPosition));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 0, 0, 1);
        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 109, vector3df(-RubicElt::cube_size-RubicElt::cube_margin, -RubicElt::cube_size-RubicElt::cube_margin, CubeInitPosition+RubicElt::cube_size+RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 0, 0, 2);

        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 110, vector3df(-RubicElt::cube_size-RubicElt::cube_margin, 0, CubeInitPosition-RubicElt::cube_size-RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 0, 1, 0);
        //c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 111, vector3df(-RubicElt::cube_size-RubicElt::cube_margin, 0, CubeInitPosition));
        //m->etValue((new RubicElt(c)), 0, 1, 1);
        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 112, vector3df(-RubicElt::cube_size-RubicElt::cube_margin, 0, CubeInitPosition+RubicElt::cube_size+RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 0, 1, 2);

        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 113, vector3df(-RubicElt::cube_size-RubicElt::cube_margin, RubicElt::cube_size+RubicElt::cube_margin, CubeInitPosition-RubicElt::cube_size-RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 0, 2, 0);
        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 114, vector3df(-RubicElt::cube_size-RubicElt::cube_margin, RubicElt::cube_size+RubicElt::cube_margin, CubeInitPosition));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 0, 2, 1);
        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 115, vector3df(-RubicElt::cube_size-RubicElt::cube_margin, RubicElt::cube_size+RubicElt::cube_margin, CubeInitPosition+RubicElt::cube_size+RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 0, 2, 2);
*/
        /**Face middle**/
        /*c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 116, vector3df(0, -RubicElt::cube_size-RubicElt::cube_margin, CubeInitPosition-RubicElt::cube_size-RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 1, 0, 0);
        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 117, vector3df(0, RubicElt::cube_size+RubicElt::cube_margin, CubeInitPosition-RubicElt::cube_size-RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 1, 2, 0);
        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 118, vector3df(0, -RubicElt::cube_size-RubicElt::cube_margin, CubeInitPosition+RubicElt::cube_size+RubicElt::cube_margin));    selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 1, 0, 2);
        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 119, vector3df(0, RubicElt::cube_size+RubicElt::cube_margin, CubeInitPosition+RubicElt::cube_size+RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 1, 2, 2);
*/
        /**Face forward**/
        /*c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 120, vector3df(RubicElt::cube_size+RubicElt::cube_margin, -RubicElt::cube_size-RubicElt::cube_margin, CubeInitPosition-RubicElt::cube_size-RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 2, 0, 0);
        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 121, vector3df(RubicElt::cube_size+RubicElt::cube_margin, -RubicElt::cube_size-RubicElt::cube_margin, CubeInitPosition));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 2, 0, 1);
        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 122, vector3df(RubicElt::cube_size+RubicElt::cube_margin, -RubicElt::cube_size-RubicElt::cube_margin, CubeInitPosition+RubicElt::cube_size+RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 2, 0, 2);

        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, c_c, 123, vector3df(RubicElt::cube_size+RubicElt::cube_margin, 0, CubeInitPosition-RubicElt::cube_size-RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 2, 1, 0);
        //c = sceneManager->addMeshSceneNode(cube2CubeMesh, 0, 111, vector3df(-RubicElt::cube_size-RubicElt::cube_margin, 0, CubeInitPosition));
        //m->etValue((new RubicElt(c)), 0, 1, 1);
        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, c_c, 124, vector3df(RubicElt::cube_size+RubicElt::cube_margin, 0, CubeInitPosition+RubicElt::cube_size+RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 2, 1, 2);

        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 125, vector3df(RubicElt::cube_size+RubicElt::cube_margin, RubicElt::cube_size+RubicElt::cube_margin, CubeInitPosition-RubicElt::cube_size-RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 2, 2, 0);
        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 126, vector3df(RubicElt::cube_size+RubicElt::cube_margin, RubicElt::cube_size+RubicElt::cube_margin, CubeInitPosition));
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 2, 2, 1);
        //c = sceneManager->addMeshSceneNode(cube2CubeMesh, 0, 127, vector3df(RubicElt::cube_size+RubicElt::cube_margin, RubicElt::cube_size+RubicElt::cube_margin, CubeInitPosition+RubicElt::cube_size+RubicElt::cube_margin));
        //m->setValue((new RubicElt(c)), 2, 2, 2);
        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, 127, vector3df(RubicElt::cube_size+RubicElt::cube_margin, RubicElt::cube_size+RubicElt::cube_margin, CubeInitPosition+RubicElt::cube_size+RubicElt::cube_margin));
            //c->setMaterialFlag(video::EMF_LIGHTING, false);
            selector = sceneManager->createTriangleSelector(c);
            c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c)), 2, 2, 2);
*/
    /* Bloc du intérieurs */
        /*IAnimatedMeshSceneNode *c_c = sceneManager->addAnimatedMeshSceneNode(blackCubeMesh, 0, 100,
                                                                                vector3df(RubicCube::CubeInitPosition.X+RubicElt::cube_size+RubicElt::cube_margin,
                                                                                    RubicCube::CubeInitPosition.Y+RubicElt::cube_size+RubicElt::cube_margin,
                                                                                    RubicCube::CubeInitPosition.Z+RubicElt::cube_size+RubicElt::cube_margin));
            selector = sceneManager->createTriangleSelector(c_c);
            c_c->setTriangleSelector(selector);
            m->setValue((new RubicElt(c_c, 1, 1, 1)), 1, 1, 1);
*/
        IAnimatedMeshSceneNode *c;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if(i == 1 && j == 1 && k == 1
                        || i == 1 && j == 1 && k == 0
                        || i == 0 && j == 1 && k == 1
                        || i == 2 && j == 1 && k == 1
                        || i == 1 && j == 0 && k == 1
                        || i == 1 && j == 2 && k == 1
                        || i == 1 && j == 1 && k == 2){
                        c = sceneManager->addAnimatedMeshSceneNode(blackCubeMesh, 0, /*100+(i*j*k)*/100+(i+j*10+k*100),
                                                                        vector3df(RubicCube::CubeInitPosition.X+i*(RubicElt::cube_size+RubicElt::cube_margin),
                                                                            RubicCube::CubeInitPosition.Y+j*(RubicElt::cube_size+RubicElt::cube_margin),
                                                                            RubicCube::CubeInitPosition.Z+k*(RubicElt::cube_size+RubicElt::cube_margin)));
                        selector = sceneManager->createTriangleSelector(c);
                        c->setTriangleSelector(selector);
                        //m->setValue((new RubicElt(c, i, j, k)), i, j, k);
                        m->setValue((new RubicElt(c)), i, j, k);
                        //c->setDebugDataVisible(irr::scene::EDS_FULL);

                    }else{
                        c = sceneManager->addAnimatedMeshSceneNode(cube2CubeMesh, 0, /*100+(i*j*k)*/100+(i+j*10+k*100),
                                                                        vector3df(RubicCube::CubeInitPosition.X+i*(RubicElt::cube_size+RubicElt::cube_margin),
                                                                            RubicCube::CubeInitPosition.Y+j*(RubicElt::cube_size+RubicElt::cube_margin),
                                                                            RubicCube::CubeInitPosition.Z+k*(RubicElt::cube_size+RubicElt::cube_margin)));
                        selector = sceneManager->createTriangleSelector(c);
                        c->setTriangleSelector(selector);
                        //m->setValue((new RubicElt(c, i, j, k)), i, j, k);
                        m->setValue((new RubicElt(c)), i, j, k);
                        //c->setDebugDataVisible(irr::scene::EDS_FULL);

                    }
                }
            }
        }

    }

    void RubicCube::rotate(RubicElt *elt, irr::core::vector3df face){
        elt->anode->setRotation(irr::core::vector3df(0, 0, 10.f));
    }

    RubicElt *RubicCube::getRubicElt(int x, int y, int z){
        return m->getValue(x, y, z);
    }

}
