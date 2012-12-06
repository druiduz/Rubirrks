#ifndef _RUBICELT_H_
#define _RUBICELT_H_

#include "header.h"

using namespace irr;
using namespace scene;

namespace rubic {

    struct RubicElt {

        public:
            RubicElt(ISceneNode *node, int x, int y, int z);
            RubicElt(ISceneNode *node);
            RubicElt(IAnimatedMeshSceneNode *anode);
            RubicElt();
            ~RubicElt();

            irr::scene::ISceneNode *node;
            irr::scene::IAnimatedMeshSceneNode *anode;
            irr::core::vector3df position;  /** (-1, 1, 0) **/

            int getFace();
            void refreshTriangleSelector(scene::ITriangleSelector *triangleSelector);
            int faceIsOnPoint(core::vector3df &point);

            static int cube_size;
            static int cube_margin;

        protected:
            void initFaceTriangle();

            bool isCenter;

            irr::core::triangle3df *u;
            irr::core::triangle3df *d;
            irr::core::triangle3df *n;
            irr::core::triangle3df *s;
            irr::core::triangle3df *e;
            irr::core::triangle3df *w;

    };
}

#endif
