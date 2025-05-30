/**
 * @file main.cpp
 * @brief prueba de la clase matrix y funcionamiento del codigo
 * @author Carlos Andrés Gloria Cortes
 * @date 30/05/2025
 */

#include <iostream>
#include "MatrixOp.h"

int main() {
    MatrixOp M(3, 3);
    for (int i = 0; i < M.getRows(); ++i) {
        for (int j = 0; j < M.getCols(); ++j) {
            M.set(i, j,
                  i * M.getCols() + j + 1.0);  // Asignar valores a la matriz
        }
    }

    // Mostrar la matriz
    std::cout << "Matriz M:" << std::endl;
    for (int i = 0; i < M.getRows(); ++i) {
        for (int j = 0; j < M.getCols(); ++j) {
            std::cout << M.get(i, j) << " ";  // Imprimir cada elemento
        }
        std::cout << std::endl;  // Nueva línea al final de cada fila
    }
    // Mostrar el número de filas y columnas
    std::cout << "Número de filas: " << M.getRows() << std::endl;
    std::cout << "Número de columnas: " << M.getCols() << std::endl;
    MatrixOp m(3, 3);
    m.set(1, 2, 42.5); // Asigna un valor
    std::cout << "Valor en (1,2): " << m.get(1, 2) << std::endl;
}
