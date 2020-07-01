//
// Created by mfbut on 5/14/2019.
//


#include "VectorDimensionMismatchError.h"
#include <iostream>
#include <sstream>


const char *Matrix::VectorDimensionMismatchError::what() const noexcept {
    return errorString.c_str();
}




Matrix::VectorDimensionMismatchError::VectorDimensionMismatchError(int line_number, const char* file_name) :
    line_number(line_number), file_name(file_name)
{

    std::stringstream errorStream;
    errorStream << "A VectorDimensionError occurred in " << file_name << ":" << line_number << std::endl;
    errorString = errorStream.str();

}
