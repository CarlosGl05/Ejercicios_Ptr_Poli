/**
 * @file main.cpp
 * @brief Archivo prueba determinante
 * @author Carlos Andrés Gloria Cortes
 * @date 30/05/2025
 * pega los main de los archivos test y prueba los resultados
 */

#include <iostream>
#include "MatrixOp.h"

int main() {
    IMatrix *mat = new MatrixOp(2, 2);
    // Asignar valores
    MatrixOp* mop = dynamic_cast<MatrixOp*>(mat);
    mop->set(0, 0, 1);
    mop->set(0, 1, 2);
    mop->set(1, 0, 3);
    mop->set(1, 1, 4);

    std::cout << "Determinante: " << mat->determinant() << "\n";
    delete mat;
    return 0;
}