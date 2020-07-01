//
// Created by mfbut on 5/19/2019.
//

#ifndef MATRIX_DIVIDEBYZEROERROR_H
#define MATRIX_DIVIDEBYZEROERROR_H

//used to signify an attempted division by scalar value 0
#include "MatrixError.h"

namespace Matrix  {

  //should inherit from MatrixError
class DivideByZeroError : public MatrixError {
public:
    DivideByZeroError(int line_number, const char* file_name);

    const char* what() const noexcept override ;

protected:
    int line_number;
    const char* file_name;

  };

}
#define MAKE_DIVIDE_BY_ZERO_ERROR() DivideByZeroError(__LINE__, __FILE__)

#endif //MATRIX_DIVIDEBYZEROERROR_H
