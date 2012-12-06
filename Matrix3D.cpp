#include "Matrix3D.h"
#include "RubicElt.h"

namespace rubic {

    Matrix3D::Matrix3D(int l){
        this->size = l;
        m = (RubicElt ****)malloc(size*sizeof(RubicElt ***));
        for(int i = 0; i < size; i++){
            m[i] = (RubicElt ***)malloc(size*sizeof(RubicElt **));
            for(int j = 0; j < size; j++){
                m[i][j] = (RubicElt **)malloc(size*sizeof(RubicElt *));
            }
        }
    }

    Matrix3D::~Matrix3D(){
        /*for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                for(int k = 0; k < size; k++){
                    free(m[i][j][k]);
                }
            }
        }*/
    }

    void Matrix3D::setValue(RubicElt *elt, int x, int y, int z){
        m[x][y][z] = elt;
    }

    RubicElt* Matrix3D::getValue(int x, int y, int z){
        return m[x][y][z];
    }
}
