﻿#include "BooleanMatrix.h"


int main() {
    matrix<int> myMatrix(5, 5);
    myMatrix.fill(
        0,0,1,0,1,
        1,0,1,1,0,
        0,0,0,1,0,
        1,1,1,1,1,
        1,0,1,1,1
    );

    myMatrix.print();

    std::cout << std::endl;

    boolMatrix mtx(&myMatrix);
    mtx.print();

    if (mtx.isReflexive()) {
        std::cout << "Матриця рефлективна" << std::endl;
    }

    if (mtx.isAntisymmetric()) {
        std::cout << "Матриця асиметрична" << std::endl;
    }

    if (mtx.isTransitive()) {
        std::cout << "Матриця транзитивна" << std::endl;
    }



    if (mtx.isEquivalence()) {
        std::cout << "Матриця рефлективна" << std::endl;
    }

    if (mtx.isPartialOrder()) {
        std::cout << "Матриця асиметрична" << std::endl;
    }

    if (mtx.isStrictOrder()) {
        std::cout << "Матриця транзитивна" << std::endl;
    }

    return 0;
}