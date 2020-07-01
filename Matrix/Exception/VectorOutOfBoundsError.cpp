//
// Created by mfbut on 5/14/2019.
//


#include "VectorOutOfBoundsError.h"

#include "OutOfBoundsError.h"
#include "MatrixError.h"
#include "Vector.h"
#include <sstream>


Matrix::VectorOutOfBoundsError::VectorOutOfBoundsError(const Vector &vec, int index)
        : vectorSize(vec.size()), indexAccessed(index){
    std::stringstream errorStream;
    errorStream << "Index out of Bounds error"<< std::endl;
}
int Matrix::VectorOutOfBoundsError::getVectorSize() const {
    return vectorSize;
}

int Matrix::VectorOutOfBoundsError::getIndexSize() const {
    return indexAccessed;
}




