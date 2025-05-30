/**
 * @file main.cpp
 * @brief Archivo principal para probar la funcion diagonal 
 * @author Carlos Andrés Gloria Cortes
 * @date 30/05/2025
 */

#include <iostream>
#include "MatrixOp.h"

int main() {
    MatrixOp m(3, 3);

    int val = 1;
    for (int i = 0; i < m.getRows(); ++i) {
        for (int j = 0; j < m.getCols(); ++j) {
            m.set(i, j, val++);
        }
    }

    m.forEachDiagonal(&MatrixOp::printAt);

    return 0;
}
