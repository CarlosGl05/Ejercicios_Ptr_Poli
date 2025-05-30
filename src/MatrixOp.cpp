/**
 * @file TemplateClass.cpp
 * @brief Implementación de TemplateClass.
 * @date YYYY-MM-DD
 * @author Camilo Duque
 *
 */

#include "MatrixOp.h"

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
