/**
 * @file main.cpp
 * @brief Archivo prueba funcion apply
 * @author Carlos Andrés Gloria Cortes
 * @date 30/05/2025
 */

#include <iostream>
#include "MatrixOp.h"

int main() {
    MatrixOp A(2, 2);
    MatrixOp B(2, 2);
    MatrixOp C(2, 2);
    MatrixOp D(2, 2);

    A.set(0, 0, 1);
    A.set(0, 1, 2);
    B.set(0, 0, 3);
    B.set(0, 1, 4);
    A.apply(&A, &B, &C, [](double a, double b) { return a - b; });

    A.apply(&A, &B, &D, [](double a, double b) { return a * b; });


    std::cout << "Matrix C:" << std::endl;
    for (int i = 0; i < C.getRows(); i++) {
        for (int j = 0; j < C.getCols(); j++) {
            std::cout << C.get(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix D:" << std::endl;
    for (int i = 0; i < D.getRows(); i++) {
        for (int j = 0; j < D.getCols(); j++) {
            std::cout << D.get(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

