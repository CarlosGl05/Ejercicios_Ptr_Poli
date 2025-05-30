/**
 * @file MatrixOp.cpp
 * @brief Implementación de matrix
 * @date 30/05/2025
 * @author Carlos Gloria Cortes
 *
 */

#include "MatrixOp.h"
#include <stdexcept>
#include <iostream>

MatrixOp::MatrixOp(int rows, int cols)
    : rows_(rows), cols_(cols), data_(nullptr) {
    if (rows_ <= 0 || cols_ <= 0) {
        throw std::invalid_argument(
            "Rows and columns must be positive integers.");
    }
    data_ = new double[rows_ * cols_];
    for (int i = 0; i < rows_ * cols_; ++i) {
        data_[i] = 0.0;  // Initialize all elements to zero
    }
}
MatrixOp::~MatrixOp() {
    delete[] data_;  
    data_ = nullptr;  
}

// Setter
void MatrixOp::set(int i, int j, double v) {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_)
        throw std::out_of_range("Index out of range.");
    data_[i * cols_ + j] = v;
}
// Getter
double MatrixOp::get(int i, int j) const {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_)
        throw std::out_of_range("Index out of range.");
    return data_[i * cols_ + j];
}
// Add

void MatrixOp::add(const MatrixOp *other, MatrixOp *result) const {
    if (rows_ != other->getRows() || cols_ != other->getCols() ||
        rows_ != result->getRows() || cols_ != result->getCols()) {
        throw std::invalid_argument("Dimensiones diferentes.");
    }
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result->set(i, j, this->get(i, j) + other->get(i, j));
        }
    }
}

// apply funcion generica

void MatrixOp::apply(const MatrixOp *A, const MatrixOp *B, MatrixOp *out, OpFunc op) const {
    for (int i = 0; i < A->getRows(); ++i) {
        for (int j = 0; j < A->getCols(); ++j) {
            out->set(i, j, op(A->get(i, j), B->get(i, j)));
        }
    }
}   

// por cada diagonal
void MatrixOp::forEachDiagonal(void (MatrixOp::*fn)(int i, int j) const) const {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            if (i == j) {
                (this->*fn)(i, j);
            }
        }
    }
}

void MatrixOp::printAt(int i, int j) const {
    std::cout << get(i, j) << " ";
}

MatrixOp MatrixOp::operator+(const MatrixOp &other) const {
    if (rows_ != other.getRows() || cols_ != other.getCols()) {
        throw std::invalid_argument("Dimensiones incompatibles");
    }
    MatrixOp result(rows_, cols_);
    int total = rows_ * cols_;
    for (int k = 0; k < total; ++k) {
        result.data_[k] = this->data_[k] + other.data_[k];
    }
    return result;
}

MatrixOp MatrixOp::operator-(const MatrixOp &other) const {
    if (rows_ != other.getRows() || cols_ != other.getCols()) {
        throw std::invalid_argument("Dimensiones incompatibles");
    }
    MatrixOp result(rows_, cols_);
    int total = rows_ * cols_;
    for (int k = 0; k < total; ++k) {
        result.data_[k] = this->data_[k] - other.data_[k];
    }
    return result;
}

double MatrixOp::determinant() const {
    if (rows_ == 2 && cols_ == 2) {
        // |a b|
        // |c d| = a*d - b*c
        return get(0,0)*get(1,1) - get(0,1)*get(1,0);
    } else if (rows_ == 3 && cols_ == 3) {
        // Regla de Sarrus
        double a = get(0,0), b = get(0,1), c = get(0,2);
        double d = get(1,0), e = get(1,1), f = get(1,2);
        double g = get(2,0), h = get(2,1), i = get(2,2);
        return a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h;
    } else {
        throw std::logic_error("Implementar para 2x2 o 3x3");
    }
}