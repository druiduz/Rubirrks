#ifndef _MATRIX3D_H_
#define _MATRIX3D_H_

#include "header.h"

namespace rubic {

struct RubicElt;

    class Matrix3D {

        public:
            Matrix3D(int l);
            ~Matrix3D();

            void setValue(RubicElt *elt, int x, int y, int z);
            RubicElt* getValue(int x, int y, int z);

        protected:
            RubicElt ****m;
            int size;

    };

};

#endif
