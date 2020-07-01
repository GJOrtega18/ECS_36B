//
// Created by mfbut on 5/14/2019.
//

#ifndef MATRIX_VECTOROUTOFBOUNDSERROR_H
#define MATRIX_VECTOROUTOFBOUNDSERROR_H

#include "OutOfBoundsError.h"
#include "MatrixError.h"
//used t signify that the index used to access
//an element in the Vector is out of bounds
namespace Matrix {
    class Vector;
    //should inherit from OutOfBoundsError
    class VectorOutOfBoundsError : public OutOfBoundsError{
    public:
        VectorOutOfBoundsError(const Vector &vec, int index);

    protected:
        int vectorSize, indexAccessed;
    public:
        int getVectorSize() const;
        int getIndexSize() const;

    };
}

#endif //MATRIX_VECTOROUTOFBOUNDSERROR_H
