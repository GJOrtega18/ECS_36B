//
// Created by mfbut on 5/14/2019.
//

#include "MatrixOutOfBoundsError.h"

#include "OutOfBoundsError.h"
#include "MatrixError.h"
#include "Matrix.h"
#include <sstream>

Matrix::MatrixOutOfBoundsError::MatrixOutOfBoundsError(const Matrix &matrix, int index)
        : numRows(matrix.getNumRows()), numCols(matrix.getNumCols()), indexAccessed(index){
    std::stringstream errorStream;
    errorStream << "Index out of bounds error"<< std::endl;
    errorString = errorStream.str();
}


int Matrix::MatrixOutOfBoundsError::getIndexAccessed() const {
    return indexAccessed;
}

int Matrix::MatrixOutOfBoundsError::getNumRows() const {
    return numRows;
}

int Matrix::MatrixOutOfBoundsError::getNumCols() const {
    return numCols;
}
