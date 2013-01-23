#include "RubicElt.h"

namespace rubic {

    float RubicElt::cube_size = 10.0f;
    float RubicElt::cube_margin = 5.f;

    RubicElt::RubicElt(ISceneNode *node, int x, int y, int z) :
            n(0), s(0), b(0), f(0), e(0), w(0)
    {
        this->anode = anode;
        initFaceTriangle();
    }

    RubicElt::RubicElt(ISceneNode *node){
        this->node = node;
        initFaceTriangle();
    }

    RubicElt::RubicElt(IAnimatedMeshSceneNode *anode){
        this->anode = anode;
        initFaceTriangle();
    }

    RubicElt::RubicElt(){
        this->node = NULL;
    }

    void RubicElt::initFaceTriangle(){
        n = (irr::core::triangle3df *) calloc(2, sizeof(irr::core::triangle3df));
        s = (irr::core::triangle3df *) calloc(2, sizeof(irr::core::triangle3df));
        b = (irr::core::triangle3df *) calloc(2, sizeof(irr::core::triangle3df));
        f = (irr::core::triangle3df *) calloc(2, sizeof(irr::core::triangle3df));
        e = (irr::core::triangle3df *) calloc(2, sizeof(irr::core::triangle3df));
        w = (irr::core::triangle3df *) calloc(2, sizeof(irr::core::triangle3df));

        //North
        n[0] = irr::core::triangle3df(
                                    irr::core::vector3df( 0, RubicElt::cube_size, 0 ),
                                    irr::core::vector3df( 0, RubicElt::cube_size, RubicElt::cube_size ),
                                    irr::core::vector3df( RubicElt::cube_size, RubicElt::cube_size, 0 )
                                    );
        n[1] = irr::core::triangle3df(
                                    irr::core::vector3df(0, RubicElt::cube_size, RubicElt::cube_size),
                                    irr::core::vector3df(RubicElt::cube_size, RubicElt::cube_size, RubicElt::cube_size),
                                    irr::core::vector3df(RubicElt::cube_size, RubicElt::cube_size, 0)
                                    );

        //South
        s[0] = irr::core::triangle3df(
                                    irr::core::vector3df( 0, 0, 0 ),
                                    irr::core::vector3df( 0, 0, RubicElt::cube_size ),
                                    irr::core::vector3df( RubicElt::cube_size, 0, 0 )
                                    );
        s[1] = irr::core::triangle3df(
                                    irr::core::vector3df(0, 0, RubicElt::cube_size),
                                    irr::core::vector3df(RubicElt::cube_size, 0, RubicElt::cube_size),
                                    irr::core::vector3df(RubicElt::cube_size, 0, 0)
                                    );

        //Back
        b[0] = irr::core::triangle3df(
                                    irr::core::vector3df( RubicElt::cube_size, 0, 0 ),
                                    irr::core::vector3df( RubicElt::cube_size, 0, RubicElt::cube_size ),
                                    irr::core::vector3df( RubicElt::cube_size, RubicElt::cube_size, 0 )
                                    );
        b[1] = irr::core::triangle3df(
                                    irr::core::vector3df(RubicElt::cube_size, 0, RubicElt::cube_size),
                                    irr::core::vector3df(RubicElt::cube_size, RubicElt::cube_size, RubicElt::cube_size),
                                    irr::core::vector3df(RubicElt::cube_size, RubicElt::cube_size, 0)
                                    );

        //Front
        f[0] = irr::core::triangle3df(
                                    irr::core::vector3df( 0, 0, 0 ),
                                    irr::core::vector3df( 0, 0, RubicElt::cube_size ),
                                    irr::core::vector3df( 0, RubicElt::cube_size, 0 )
                                    );
        f[1] = irr::core::triangle3df(
                                    irr::core::vector3df(0, 0, RubicElt::cube_size),
                                    irr::core::vector3df(0, RubicElt::cube_size, RubicElt::cube_size),
                                    irr::core::vector3df(0, RubicElt::cube_size, 0)
                                    );

        //East
        e[0] = irr::core::triangle3df(
                                    irr::core::vector3df( 0, 0, RubicElt::cube_size ),
                                    irr::core::vector3df( RubicElt::cube_size, 0, RubicElt::cube_size ),
                                    irr::core::vector3df( 0, RubicElt::cube_size, RubicElt::cube_size )
                                    );
        e[1] = irr::core::triangle3df(
                                    irr::core::vector3df(RubicElt::cube_size, RubicElt::cube_size, RubicElt::cube_size),
                                    irr::core::vector3df(0, RubicElt::cube_size, RubicElt::cube_size),
                                    irr::core::vector3df(RubicElt::cube_size, 0, RubicElt::cube_size)
                                    );

        //West
        w[0] = irr::core::triangle3df(
                                    irr::core::vector3df( 0, 0, 0 ),
                                    irr::core::vector3df( RubicElt::cube_size, 0, 0 ),
                                    irr::core::vector3df( 0, RubicElt::cube_size, 0 )
                                    );
        w[1] = irr::core::triangle3df(
                                    irr::core::vector3df(RubicElt::cube_size, RubicElt::cube_size, 0),
                                    irr::core::vector3df(0, RubicElt::cube_size, 0),
                                    irr::core::vector3df(RubicElt::cube_size, 0, 0)
                                    );
    }

    void RubicElt::refreshTriangleSelector(scene::ITriangleSelector *triangleSelector){

    }

    int RubicElt::faceIsOnPoint(core::vector3df &point){
        fprintf(stdout, "point (%f, %f, %f)\n", point.X, point.Y, point.Z);
        fprintf(stdout, "--F1 (%f, %f, %f) (%f, %f, %f) (%f, %f, %f)\n", f[0].pointA.X, f[0].pointA.Y, f[0].pointA.Z, f[0].pointB.X, f[0].pointB.Y, f[0].pointB.Z, f[0].pointC.X, f[0].pointC.Y, f[0].pointC.Z);
        //fprintf(stdout, "--F2 (%f, %f, %f) (%f, %f, %f) (%f, %f, %f)\n", f[1].pointA.X, f[1].pointA.Y, f[1].pointA.Z, f[1].pointB.X, f[1].pointB.Y, f[1].pointB.Z, f[1].pointC.X, f[1].pointC.Y, f[1].pointC.Z);
        if( n[0].isPointInside(point) || n[1].isPointInside(point) ) { return 1; }
        if( s[0].isPointInside(point) || s[1].isPointInside(point) ) { return 2; }
        if( b[0].isPointInside(point) || b[1].isPointInside(point) ) { return 3; }
        if( f[0].isPointInside(point) || f[1].isPointInside(point) ) { return 4; }
        if( e[0].isPointInside(point) || e[1].isPointInside(point) ) { return 5; }
        if( w[0].isPointInside(point) || w[1].isPointInside(point) ) { return 6; }
        return 0;
    }

}
