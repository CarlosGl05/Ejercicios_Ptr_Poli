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

   private:
    double *data_;
    int rows_;
    int cols_;
};

#endif  // MatrixOp_H