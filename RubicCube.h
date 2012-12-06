#ifndef _RUBICCUBE_H_
#define _RUBICCUBE_H_

#include "header.h"

using namespace irr;
using namespace scene;
using namespace core;

namespace rubic {

struct RubicElt;
class Matrix3D;

    class RubicCube {

        public:
            RubicCube(ISceneManager *scene);
            ~RubicCube();

            void rotate(RubicElt *elt, irr::core::vector3df face);

            RubicElt *getRubicElt(int x, int y, int z);

            enum Face
            {
                F_North,
                F_South,
                F_West,
                F_East,
                F_Forward,
                F_Backward
            };

            static irr::core::vector3df CubeInitPosition;

        protected:
            ISceneManager *sceneManager;
            Matrix3D *m;

            void generateRubicCube();
            bool isResolvable();

            int getFace(const irr::core::vector3df &face);

            bool isComplete();

    };
}

#endif
