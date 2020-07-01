//
// Created by mfbut on 5/14/2019.
//


#include "MatrixDimensionMismatchError.h"


Matrix::MatrixDimensionMismatchError::MatrixDimensionMismatchError(int line_number, const char *file_name):
        line_number(line_number),
        file_name(file_name) {
    std::stringstream errorStream;
    errorStream << "A MatrixDimensionMismatchError occurred in " << file_name << ":" << line_number << std::endl;
    errorString = errorStream.str();

}

