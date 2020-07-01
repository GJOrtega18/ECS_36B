//
// Created by mfbut on 5/14/2019.
//
#include "MatrixInnerDimensionMismatchError.h"


Matrix::MatrixInnerDimensionMismatchError::MatrixInnerDimensionMismatchError(
                                                                             int line_number,
                                                                             const char *file_name)
        : MatrixDimensionMismatchError(line_number, file_name) {
    this->line_number = line_number;
    this->file_name = file_name;
    std::stringstream errorStream;
    errorStream << "A MatrixInnerDimensionMismatchError occurred in " << file_name << ":" << line_number << std::endl;
    errorString = errorStream.str();
}
