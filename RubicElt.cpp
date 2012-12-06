#include "RubicElt.h"

namespace rubic {

    int RubicElt::cube_size = 10.0f;
    int RubicElt::cube_margin = 5.f;

    RubicElt::RubicElt(ISceneNode *node, int x, int y, int z) {
        this->anode = anode;

        initFaceTriangle();

    }

    RubicElt::RubicElt(ISceneNode *node){
        this->node = node;
    }

    RubicElt::RubicElt(IAnimatedMeshSceneNode *anode){
        this->anode = anode;
    }

    RubicElt::RubicElt(){
        this->node = NULL;
    }

    void RubicElt::initFaceTriangle(){
        u = (irr::core::triangle3df *)calloc(4, sizeof(irr::core::triangle3df));
        //u[0] = irr::core::triangle3df();
        u[0] = irr::core::triangle3df(
                                    irr::core::vector3df(
                                                        0,
                                                        RubicElt::cube_size,
                                                        0
                                                        ),
                                    irr::core::vector3df(
                                                        0,
                                                        RubicElt::cube_size,
                                                        RubicElt::cube_size
                                                        ),
                                    irr::core::vector3df(
                                                        RubicElt::cube_size,
                                                        RubicElt::cube_size,
                                                        0
                                                        )
                                    );
        u[1] = irr::core::triangle3df(
                                    irr::core::vector3df(0, RubicElt::cube_size, RubicElt::cube_size),
                                    irr::core::vector3df(RubicElt::cube_size, RubicElt::cube_size, RubicElt::cube_size),
                                    irr::core::vector3df(RubicElt::cube_size, RubicElt::cube_size, 0)
                                    );
    }

    void RubicElt::refreshTriangleSelector(scene::ITriangleSelector *triangleSelector){

    }

    int RubicElt::faceIsOnPoint(core::vector3df &point){

    }

}
