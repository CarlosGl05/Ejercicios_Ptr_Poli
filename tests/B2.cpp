/**
 * @file main.cpp
 * @brief Archivo prueba de plantilla
 * @author Carlos Andrés Gloria Cortes
 * @date 30/05/2025
 * pega los main de los archivos test y prueba los resultados
 */

#include <iostream>
#include "MatrixOp.h"

int main() {
    MatrixOp M(3, 3);

    double v = 10.5;
    for (int i = 0; i < M.getRows(); ++i) {
        for (int j = 0; j < M.getCols(); ++j) {
            M.set(i, j, v);
            v += 4.5; 
        }
    }

    double maxElem = maxValue<double>(M.data(), M.size());
    std::cout << "maximo " << maxElem << std::endl;

    return 0;
}