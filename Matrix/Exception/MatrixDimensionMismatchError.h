//
// Created by mfbut on 5/14/2019.
//

#ifndef MATRIX_MATRIXDIMENSIONMISMATCHERROR_H
#define MATRIX_MATRIXDIMENSIONMISMATCHERROR_H


//used to signify that the operation requested to be
//performed on the matrices cannot be done because
//they are not the same size
#include "DimensionMismatchError.h"

namespace Matrix {

    //should inherit from DimensionMismatchError
    class MatrixDimensionMismatchError : public DimensionMismatchError {
    public:
        MatrixDimensionMismatchError(int line_number, const char* file_name);

    private:
        int line_number;
        const char* file_name;
    };
#define MAKE_MATRIX_DIMENSION_MISMATCH_ERROR() MatrixDimensionMismatchError(__LINE__, __FILE__)

}

#endif //MATRIX_MATRIXDIMENSIONMISMATCHERROR_H
