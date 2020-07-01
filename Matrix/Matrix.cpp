//
// Created by mfbut on 5/2/2019.
//
#include <Exception/DivideByZeroError.h>
#include <Exception/MatrixDimensionMismatchError.h>
#include <Exception/MatrixInnerDimensionMismatchError.h>
#include <Exception/MatrixOutOfBoundsError.h>
#include "Vector.h"
#include "Matrix.h"

Matrix::Matrix Matrix::Matrix::ident(Matrix::SizeType dim) {
    Matrix idenMatrix = Matrix(dim, dim);
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
            if (j == i){
                idenMatrix.at(j).at(i) = 1;
            }
        }
    }return idenMatrix;
}

Matrix::Matrix::Matrix(Matrix::SizeType numRows, Matrix::SizeType numCols, const Matrix::ValueType &val)

{   std::vector<Vector> rows;

    for(int row = 0; row != numRows; row++){
        rows.emplace_back(numCols, val);

    }
    contents = rows;

}


Matrix::Matrix::Matrix(Matrix::SizeType numRows, Matrix::SizeType numCols) {
    std::vector<Vector> rows;

    for(int row = 0; row != numRows; row++){
        rows.emplace_back(numCols, 0);

    }
    contents = rows;
}


Matrix::Matrix::Matrix(const std::vector<::Matrix::Vector>& contents)
{
    for(const auto& vector: contents){
        this->contents.push_back(vector);

    }
}

Matrix::Matrix::Matrix(const std::vector<std::vector<Matrix::ValueType>> &contents)  {

    for(const auto& vector: contents){
        this->contents.push_back(vector);

    }
}

Matrix::Vector &Matrix::Matrix::at(int row) {
    if(row < 0 || row >= signed(contents.size())){
        throw MatrixOutOfBoundsError(*this, row);
    }
    return contents[row];
}

const Matrix::Vector &Matrix::Matrix::at(int row) const {
    if(row < 0 || row >= signed(contents.size())){
        throw MatrixOutOfBoundsError(*this, row);
    }
    return contents[row];
}

Matrix::Vector &Matrix::Matrix::operator[](int row) {
    return at(row);
}

const Matrix::Vector &Matrix::Matrix::operator[](int row) const {
    return at(row);
}

Matrix::ValueType &Matrix::Matrix::at(int row, int col) {
    if(row < 0 || row >= signed(contents.size())
    || col < 0 || col >= signed(contents.at(row).size())){
        throw MatrixOutOfBoundsError(*this, row);
    }
    return contents.at(row).at(col);
}

const Matrix::ValueType &Matrix::Matrix::at(int row, int col) const {
    if(row < 0 || row >= signed(contents.size())
       || col < 0 || col >= signed(contents.at(row).size())){
        throw MatrixOutOfBoundsError(*this, row);
    }
    return contents.at(row).at(col);
}

Matrix::SizeType Matrix::Matrix::getNumRows() const {
    return contents.size();
}

Matrix::SizeType Matrix::Matrix::getNumCols() const {
    return at(0).size();
}

Matrix::Matrix Matrix::Matrix::transpose() const {
    Matrix transpose_matrix = Matrix(contents.at(0).size(), contents.size());
    for( int i = 0; i != getNumCols(); i++){
        for( int j = 0; j != getNumRows(); j++){
            transpose_matrix.at(i,j) = contents.at(j).at(i);
        }
    }return transpose_matrix;
}


std::ostream& Matrix::operator<<(std::ostream &out, const Matrix& matrix) {
    for(int i = 0; i != matrix.getNumRows(); i++){
        out << matrix[i] << std::endl;
    }
    return out;
}

Matrix::Matrix Matrix::operator-(const Matrix& self) {
    Matrix copy(self);
    for(int row = 0; row != copy.getNumRows(); row++){
        copy.at(row) = -copy.at(row);
    }
    return copy;
}

// MATRIX AND SCALAR ADDITION

Matrix::Matrix Matrix::operator+(const Matrix &matrix, const Matrix::ValueType &scalar) {
    Matrix copy(matrix);
    for(int row = 0; row != copy.getNumRows(); row++){
        copy.at(row) += scalar;
    }
    return copy;
}

Matrix::Matrix Matrix::operator+(const Matrix::ValueType &scalar, const Matrix &matrix) {
    return matrix + scalar;
}



Matrix::Matrix &Matrix::operator+=(Matrix &matrix, const Matrix::ValueType &scalar) {
    for(int row = 0; row != matrix.getNumRows(); row++){
        matrix.at(row) += scalar;
    }
    return matrix;
}

// MATRIX AND SCALAR SUBTRACTION

Matrix::Matrix Matrix::operator-(const Matrix &matrix, const Matrix::ValueType &scalar) {
    Matrix copy(matrix);
    for(int row = 0; row != copy.getNumRows(); row++){
        copy.at(row) -= scalar;
    }
    return copy;
}


Matrix::Matrix Matrix::operator-(const Matrix::ValueType &scalar, const Matrix &matrix) {
    Matrix copy(matrix.getNumRows(), matrix.getNumCols(), scalar);
    for(int i = 0; i != copy.getNumRows(); i++){
        copy.at(i) -= matrix.at(i);
    }
    return copy;

}

Matrix::Matrix& Matrix::operator-=(Matrix &matrix, const Matrix::ValueType &scalar) {
    for(int row = 0; row != matrix.getNumRows(); row++){
        matrix.at(row) -= scalar;
    }
    return matrix;
}

//scalar and matrix multiplication

Matrix::Matrix Matrix::operator*(const Matrix &matrix, const Matrix::ValueType &scalar) {
    Matrix copy(matrix);
    for(int row = 0; row != copy.getNumRows(); row++){
        copy.at(row) *= scalar;
    }
    return copy;
}

Matrix::Matrix Matrix::operator*(const Matrix::ValueType &scalar, const Matrix& matrix) {
    return matrix * scalar;
}

Matrix::Matrix &Matrix::operator*=(Matrix &matrix, const Matrix::ValueType &scalar) {
    for(int row = 0; row != matrix.getNumRows(); row++){
        matrix.at(row) *= scalar;
    }
    return matrix;
}

// MATRIX AND SCALAR DIVISION
Matrix::Matrix Matrix::operator/(const Matrix &matrix, const Matrix::ValueType &scalar) {
    if(scalar == 0)
        throw MAKE_DIVIDE_BY_ZERO_ERROR();
    Matrix copy(matrix);
    for(int row = 0; row != copy.getNumRows(); row++){
        copy.at(row) /= scalar;
    }
    return copy;
}

Matrix::Matrix &Matrix::operator/=(Matrix &matrix, const Matrix::ValueType &scalar) {
    for(int row = 0; row != matrix.getNumRows(); row++){
        matrix.at(row) /= scalar;
    }
    return matrix;
}

// MATRIX ADDITION

Matrix::Matrix Matrix::operator+(const Matrix &lhs, const Matrix &rhs) {
    Matrix matrixPlusMatrix(lhs);
    if((lhs.getNumRows(),lhs.getNumCols()) != (rhs.getNumRows(),rhs.getNumCols())) {
        throw MAKE_MATRIX_DIMENSION_MISMATCH_ERROR();
    }
    for(int row = 0; row != matrixPlusMatrix.getNumRows(); row++) {
        for (int col = 0; col != matrixPlusMatrix.getNumCols(); col++) {
            matrixPlusMatrix.at(row, col) += rhs.at(row, col);
        }
    }
    return matrixPlusMatrix;
}

Matrix::Matrix &Matrix::operator+=(Matrix &lhs, const Matrix &rhs) {
    if((lhs.getNumRows(),lhs.getNumCols()) != (rhs.getNumRows(),rhs.getNumCols())) {
        throw MAKE_MATRIX_DIMENSION_MISMATCH_ERROR();
    }
    for(int row = 0; row != lhs.getNumRows(); row++) {
        for (int col = 0; col != lhs.getNumCols(); col++) {
            lhs.at(row, col) += rhs.at(row, col);
        }
    }
    return lhs;
}

//MATRIX SUBTRACTION


Matrix::Matrix Matrix::operator-(const Matrix &lhs, const Matrix &rhs) {
    if((lhs.getNumRows(),lhs.getNumCols()) != (rhs.getNumRows(),rhs.getNumCols())) {
        throw MAKE_MATRIX_DIMENSION_MISMATCH_ERROR();
    }
    Matrix matrixMinusMatrix(lhs);
    for(int row = 0; row != matrixMinusMatrix.getNumRows(); row++) {
        for (int col = 0; col != matrixMinusMatrix.getNumCols(); col++) {
            matrixMinusMatrix.at(row, col) -= rhs.at(row, col);
        }
    }
    return matrixMinusMatrix;
}

Matrix::Matrix &Matrix::operator-=(Matrix &lhs, const Matrix &rhs) {
    if((lhs.getNumRows(),lhs.getNumCols()) != (rhs.getNumRows(),rhs.getNumCols())) {
        throw MAKE_MATRIX_DIMENSION_MISMATCH_ERROR();
    }
    for(int row = 0; row != lhs.getNumRows(); row++) {
        for (int col = 0; col != lhs.getNumCols(); col++) {
            lhs.at(row, col) -= rhs.at(row, col);
        }
    }
    return lhs;
}

// MATRIX MULTIPLICATION
// 2X4 X 4X2
//   ^---^
// ^-------^  == 2X2

Matrix::Matrix Matrix::operator*(const Matrix &lhs, const Matrix &rhs) {
    Matrix matrixTimesMatrix(lhs.getNumRows(), rhs.getNumCols());
    if(lhs.getNumRows() != rhs.getNumCols()) {
        throw MAKE_INNER_MATRIX_DIMENSION_MISMATCH_ERROR();
    }
    for(int row = 0; row != matrixTimesMatrix.getNumRows(); row++) {
        for(int i=0; i != rhs.getNumCols(); i++){
            double value = 0;
            for (int col = 0; col != lhs.getNumCols(); col++) {
                value += (lhs.at(row, col) * rhs.at(col, i));
            }
            matrixTimesMatrix.at(row, i) = value;
        }
    }
    return matrixTimesMatrix;
}

Matrix::Matrix& Matrix::operator*=(Matrix &lhs, const Matrix &rhs) {
    Matrix matrixTimesMatrix(lhs.getNumRows(), rhs.getNumCols());
    if(lhs.getNumRows() != rhs.getNumCols()) {
        throw MAKE_INNER_MATRIX_DIMENSION_MISMATCH_ERROR();
    }
    for(int row = 0; row != matrixTimesMatrix.getNumRows(); row++) {
        for(int i=0; i != rhs.getNumCols(); i++){
            double value = 0;
            for (int col = 0; col != lhs.getNumCols(); col++) {
                value += (lhs.at(row, col) * rhs.at(col, i));
            }
            matrixTimesMatrix.at(row, i) = value;
        }
    }
    lhs = matrixTimesMatrix;
    return lhs;
}

std::istream &Matrix::operator>>(std::istream &in, Matrix &matrix) {
    for (int i = 0 ; i != matrix.getNumRows(); i++){
        for (int j = 0 ; j != matrix.getNumCols(); j++){
            in >> matrix.at(i).at(j);
        }
    }return in;
}
