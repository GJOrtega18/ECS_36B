//
// Created by mfbut on 5/14/2019.
//

#ifndef MATRIX_MATRIXERROR_H
#define MATRIX_MATRIXERROR_H


//base class used to signify an error happened in
//a vector or matrix
#include <string>
#include <iostream>
#include <sstream>
#include <exception>

namespace Matrix {

  //should inherit from std::exception
  class MatrixError : public std::exception {
  public:
      const char* what() const noexcept override;

  protected:
      std::string errorString;
  };
}

#endif //MATRIX_MATRIXERROR_H
