/**
 * @file main.cpp
 * @brief Archivo principal para probar la clase MatrixOp.
 * @author Carlos Andrés Gloria Cortes
 * @date 30/05/2025
 * pega los main de los archivos test y prueba los resultados
 */

#include <iostream>
#include "MatrixOp.h"

int main() {
    
    MatrixOp A(2, 2), B(2, 2);
    A.set(0, 0, 1.0); A.set(0, 1, 2.0);
    A.set(1, 0, 3.0); A.set(1, 1, 2.0); 
    B.set(0, 0, 2.0); B.set(0, 1, 2.0);
    B.set(1, 0, 2.0); B.set(1, 1, 3.0); 

    MatrixOp C = A + B;
    MatrixOp D = A - B;

    std::cout << C.get(0,0) << std::endl;
    std::cout << D.get(1,1) << std::endl;

    return 0;
}