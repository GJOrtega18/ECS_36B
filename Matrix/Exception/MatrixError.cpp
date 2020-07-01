//
// Created by mfbut on 5/14/2019.
//

#include "MatrixError.h"

const char *Matrix::MatrixError::what() const noexcept {
    return errorString.c_str();
}




