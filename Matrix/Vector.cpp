//
// Created by mfbut on 5/2/2019.
//


#include <Exception/VectorOutOfBoundsError.h>
#include "Exception/VectorDimensionMismatchError.h"
#include "DivideByZeroError.h"
#include "Vector.h"
#include "Matrix.h"

Matrix::Vector::Vector(const Matrix::SizeType &numElements)
{   signed int size = contents.size();
    while(size !=  numElements) {
        contents.push_back(0);
        size++;
    }
}

Matrix::Vector::Vector(const Matrix::SizeType &numElements, const Matrix::ValueType &value)
{   signed int size = contents.size();
    while(size !=  numElements) {
        contents.push_back(value);
        size++;
    }
}

Matrix::Vector::Vector(const std::vector<ValueType>& contents)
{
    for(auto& val : contents){
        this->contents.push_back(val);
    }
}

Matrix::SizeType Matrix::Vector::size() const {
    return contents.size();
}

Matrix::Matrix Matrix::Vector::asRowMatrix() const {
    std::vector<Vector> vectorMatrix;
    vectorMatrix.emplace_back(contents);
    return Matrix(vectorMatrix);

}

Matrix::Matrix Matrix::Vector::asColMatrix() const {
    std::vector<Vector> vectorMatrix;
    for(int i = 0; i != size(); i++){
        vectorMatrix.emplace_back(1,contents.at(i));
    }
    return Matrix(vectorMatrix);
}

Matrix::Vector&  Matrix::Vector::operator=(const Vector& rhs) {
    resize(rhs.size());
    for(int i = 0; i < size(); i++){
        at(i) = rhs.at(i);
    }
    return *this;
}

const Matrix::ValueType &Matrix::Vector::at(int index) const {
    if(index < 0 || index >= size()){
        throw VectorOutOfBoundsError(contents, index);
    }

    return contents[index];
}

Matrix::ValueType &Matrix::Vector::at(int index) {
    if(index < 0 || index >= size()){
        throw VectorOutOfBoundsError(contents, index);
    }
    return contents[index];
}
const Matrix::ValueType &Matrix::Vector::operator[](int index) const {
    return at(index);
}

Matrix::ValueType &Matrix::Vector::operator[](int index) {
    return at(index);
}

void Matrix::Vector::resize(int size) {
    contents.resize(size);
}

Matrix::Vector::operator Matrix() const {
    return asRowMatrix();
}



// Vector istream and ostream operations

std::ostream& Matrix::operator<<(std::ostream& out, const ::Matrix::Vector& vec) {
    for(int i = 0; i < vec.size(); i++){
        out << vec.at(i) << " ";

    }
    return out;
}

std::istream& Matrix::operator>>(std::istream &in, Vector &vec) {
    for (int i = 0; i < vec.size(); i++){
        in >> vec.at(i);
    }return in;
}


//Vector Negation

Matrix::Vector Matrix::operator-(const Vector& self) {
    Vector negative(self);
    for (int i=0; i!= negative.size(); i++){
        negative.at(i) = -negative.at(i);
    }
    return negative;
}


// Vector and Scalar addition

Matrix::Vector Matrix::operator+(const Vector& vector, const Matrix::ValueType& scalar) {
    Vector copy(vector);

    for(int i = 0; i != vector.size(); i++){
        copy.at(i) += scalar;
    }
    return copy;
}

Matrix::Vector Matrix::operator+(const Matrix::ValueType &scalar, const Vector& vector) {
    return vector + scalar;
}

Matrix::Vector& Matrix::operator+=(Vector& vector, const Matrix::ValueType &scalar) {
    for(int i = 0; i != vector.size(); i++){
        vector.at(i) += scalar;
    }
    return vector;
}


// Vector and Scalar subtraction

Matrix::Vector Matrix::operator-(const Vector &vector, const Matrix::ValueType &scalar) {
    Vector copy(vector);

    for(int i = 0; i != vector.size(); i++){
        copy.at(i) -= scalar;
    }
    return copy;
}

Matrix::Vector Matrix::operator-(const Matrix::ValueType &scalar, const Vector &vector) {
    Vector copy(vector.size(), scalar);

    for(int i = 0; i != vector.size(); i++){
        copy.at(i) -= vector.at(i);
    }
    return copy;
}

Matrix::Vector &Matrix::operator-=(Vector &vector, const Matrix::ValueType &scalar) {
    for(int i = 0; i != vector.size(); i++){
        vector.at(i) -= scalar;
    }
    return vector;
}

//scalar and vector multiplication

Matrix::Vector Matrix::operator*(const Vector &vector, const Matrix::ValueType &scalar) {
    Vector copy(vector);

    for(int i = 0; i != vector.size(); i++){
        copy.at(i) *= scalar;
    }
    return copy;
}

Matrix::Vector Matrix::operator*(const Matrix::ValueType &scalar, const Vector& vector) {
    return vector * scalar;
}

Matrix::Vector& Matrix::operator*=(Vector &vector, const Matrix::ValueType &scalar) {
    for(int i = 0; i != vector.size(); i++){
        vector.at(i) *= scalar;
    }
    return vector;
}
//scalar and vector division

Matrix::Vector Matrix::operator/(const Vector &vector, const Matrix::ValueType &scalar) {
    Vector copy(vector);
  //  try {
        if (scalar == 0)
            throw MAKE_DIVIDE_BY_ZERO_ERROR();

        for (int i = 0; i != vector.size(); i++) {
            copy.at(i) /= scalar;
        }
 //   }catch (DivideByZeroError& e){
 //       std::cout << e.what() << std::endl;
 //   }
    return copy;

}

Matrix::Vector &Matrix::operator/=(Vector &vector, const Matrix::ValueType &scalar) {
    try {
        if(scalar == 0)
            throw MAKE_DIVIDE_BY_ZERO_ERROR();
        for(int i = 0; i != vector.size(); i++){
            vector.at(i) /= scalar;
        }
    }catch (DivideByZeroError& e){
        std::cout << e.what() << std::endl;
    }

    return vector;


}


// VECTOR AND VECTOR OPERATIONS

// VECTOR ADDITION
Matrix::Vector Matrix::operator+(const Vector &lhs, const Vector &rhs) {
    Vector vectorPlusVector(lhs.size());
   // try {
        if(lhs.size() != rhs.size()) {
            throw MAKE_VECTOR_DIMENSION_MISMATCH_ERROR();
        }
        for(int i = 0; i != vectorPlusVector.size(); i++){
            vectorPlusVector.at(i) = lhs.at(i) + rhs.at(i);
        }
//    }catch (VectorDimensionMismatchError& e){
//        std::cout << e.what() << std::endl;
//    }


    return vectorPlusVector;
}

Matrix::Vector& Matrix::operator+=(Vector &lhs, const Vector &rhs) {
   // try {
        if (lhs.size() != rhs.size()) {
            throw MAKE_VECTOR_DIMENSION_MISMATCH_ERROR();
        }
        for (int i = 0; i != lhs.size(); i++) {
            lhs.at(i) += rhs.at(i);
        }
   // }catch (VectorDimensionMismatchError& e){
 //       std::cout << e.what() << std::endl;
   // }

    return lhs;
}

// VECTOR SUBTRACTION

Matrix::Vector Matrix::operator-(const Vector &lhs, const Vector &rhs) {
    Vector vectorMinusVector(lhs.size());
  //  try {
        if (lhs.size() != rhs.size()) {
            throw MAKE_VECTOR_DIMENSION_MISMATCH_ERROR();
        }
        for (int i = 0; i != vectorMinusVector.size(); i++) {
            vectorMinusVector.at(i) = lhs.at(i) - rhs.at(i);
        }
//    }catch (VectorDimensionMismatchError& e){
//        std::cout << e.what() << std::endl;
//    }
    return vectorMinusVector;
}

Matrix::Vector& Matrix::operator-=(Vector &lhs, const Vector &rhs) {
  //  try {
        if (lhs.size() != rhs.size()) {
            throw MAKE_VECTOR_DIMENSION_MISMATCH_ERROR();
        }
        for (int i = 0; i != lhs.size(); i++) {
            lhs.at(i) -= rhs.at(i);
        }
//    }catch (VectorDimensionMismatchError& e) {
//        std::cout << e.what() << std::endl;
//    }
    return lhs;
}

Matrix::ValueType Matrix::operator*(const Vector &lhs, const Vector &rhs) {
    ValueType dotProduct = 0;
  //  try {
        if (lhs.size() != rhs.size()) {
            throw MAKE_VECTOR_DIMENSION_MISMATCH_ERROR();
        }
        for (int i = 0; i != lhs.size(); i++) {
            dotProduct += (lhs.at(i) * rhs.at(i));
        }
//    }catch (VectorDimensionMismatchError& e) {
//        std::cout << e.what() << std::endl;
//    }
    return dotProduct;
}

Matrix::ValueType Matrix::operator*=(Vector &lhs, const Vector &rhs) {
    ValueType dotProduct = 0;
  //  try {
        if (lhs.size() != rhs.size()) {
            throw MAKE_VECTOR_DIMENSION_MISMATCH_ERROR();
        }
        for (int i = 0; i != lhs.size(); i++) {
            dotProduct += (lhs.at(i) * rhs.at(i));
        }
        Vector newLhs(1, dotProduct);
        lhs = newLhs;
//    }catch (VectorDimensionMismatchError& e) {
//        std::cout << e.what() << std::endl;
//    }
    return lhs.at(0);
}



