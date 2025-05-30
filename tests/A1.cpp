/**
 * @file A1
 * @brief Pruebas para A1
 * @date 30/05/2025
 */


#include <iostream>
#include "MatrixOp.h"


int main() {
    MatrixOp m(3, 3);

    m.set(0, 0, 1);
    m.set(0, 1, 2);
    m.set(0, 2, 3);
    m.set(1, 0, 4);
    m.set(1, 1, 5);
    m.set(1, 2, 6);
    m.set(2, 0, 7);
    m.set(2, 1, 8);
    m.set(2, 2, 9);


    std::cout << m.get(0, 0) << std::endl; // Debe devolver 1
    std::cout << m.get(0, 1) << std::endl; // Debe devolver 2
    std::cout << m.get(0, 2) << std::endl; // Debe devolver 3
    std::cout << m.get(1, 0) << std::endl; // Debe devolver 4
    std::cout << m.get(1, 1) << std::endl; // Debe devolver 5
    std::cout << m.get(1, 2) << std::endl; // Debe devolver 6
    std::cout << m.get(2, 0) << std::endl; // Debe devolver 7
    std::cout << m.get(2, 1) << std::endl; // Debe devolver 8
    std::cout << m.get(2, 2) << std::endl; // Debe devolver 9

}