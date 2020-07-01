//
// Created by mfbut on 5/14/2019.
//

#ifndef MATRIX_VECTORDIMENSIONMISMATCHERROR_H
#define MATRIX_VECTORDIMENSIONMISMATCHERROR_H

//used to signify that the operation can't be performed on
//the vector can't be done as they aren't the same size
#include "DimensionMismatchError.h"

namespace Matrix {
  class Vector;
  //should inherit from DimensionMismatchError
  class VectorDimensionMismatchError : public DimensionMismatchError {
  public:
      VectorDimensionMismatchError(int line_number, const char* file_name);
      const char* what() const noexcept override ;

  private:
      int line_number;
      const char* file_name;
  };
#define MAKE_VECTOR_DIMENSION_MISMATCH_ERROR() VectorDimensionMismatchError(__LINE__, __FILE__)

}

#endif //MATRIX_VECTORDIMENSIONMISMATCHERROR_H
