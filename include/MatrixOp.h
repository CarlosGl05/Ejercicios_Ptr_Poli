#ifndef MatrixOp_H
#define MatrixOp_H

#pragma once
#include <string>
#include <stdexcept>

class MatrixOp {
   public:
    MatrixOp(int rows, int cols);
    ~MatrixOp();
    void set(int i, int j, double v);
    double get(int i, int j) const;
    int getRows() const { return rows_; };
    int getCols() const { return cols_; };
    void add(const MatrixOp *other, MatrixOp *result) const;
    using OpFunc = double(*)(double, double);
    void apply(const MatrixOp *A, const MatrixOp *B, MatrixOp *out, OpFunc op) const;
    void forEachDiagonal(void (MatrixOp::*fn)(int i, int j) const) const;
    void printAt(int i, int j) const;

    MatrixOp operator+(const MatrixOp &other) const;
    MatrixOp operator-(const MatrixOp &other) const;

    const double* data() const { return data_; }
    int size() const { return rows_ * cols_; }

   private:
    double *data_;
    int rows_;
    int cols_;
};

/**
 * @brief Devuelve el valor máximo en un arreglo contiguo de longitud n.
 * @tparam T Tipo de dato (double, int, etc.)
 * @param arr Puntero al primer elemento del arreglo
 * @param n   Número de elementos
 * @return    El máximo entre arr[0] … arr[n-1]
 */
template<typename T>
T maxValue(const T*arr, int n){
    if(n <= 0) throw std::invalid_argument("El arrego debe tener al menos dos elementos");
    T max = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

#endif  // MatrixOp_H