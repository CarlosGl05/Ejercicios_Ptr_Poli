#ifndef MatrixOp_H
#define MatrixOp_H

#pragma once
#include <string>

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

   private:
    double *data_;
    int rows_;
    int cols_;
};

#endif  // MatrixOp_H