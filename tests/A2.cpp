/**
 * @file main.cpp
 * @brief Archivo para probar la funcion add
 * @author Carlos Andrés Gloria Cortes
 * @date 30/05/2025
 */

#include <iostream>
#include "MatrixOp.h"

int main() {
    MatrixOp A(2,2);
    MatrixOp B(2,2);
    MatrixOp C(2,2);
    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(1, 0, 3);
    A.set(1, 1, 4);
    B.set(0, 0, 5);
    B.set(0, 1, 6);
    B.set(1, 0, 7);
    B.set(1, 1, 8);
    A.add(&B, &C);

    std::cout << "Matrix C:" << std::endl;

    for (int i = 0; i < C.getRows(); i++){
        for (int j = 0; j < C.getCols(); j++) {
            std::cout << C.get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}
