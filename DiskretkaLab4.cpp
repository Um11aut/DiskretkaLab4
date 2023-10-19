#include "BooleanMatrix.h"
#include <utility>

int main() {
    matrix<int> myMatrix(5, 5);
    myMatrix.fill(
        0,0,1,0,1,
        1,0,1,1,0,
        0,0,0,1,0,
        1,1,1,1,1,
        1,0,1,1,1
    );

    std::cout << std::endl;

    boolMatrix mtx(&myMatrix);
    mtx.print();

    std::cout << std::endl;

    if (mtx.isReflexive()) {
        std::cout << "Матриця рефлективна" << std::endl;
    }
    else {
        std::cout << "Матриця не рефлективна" << std::endl;
    }

    if (mtx.isAntisymmetric()) {
        std::cout << "Матриця асиметрична" << std::endl;
    }
    else {
        std::cout << "Матриця не асиметрична" << std::endl;
    }

    if (mtx.isTransitive()) {
        std::cout << "Матриця транзитивна" << std::endl;
    }
    else {
        std::cout << "Матриця не транзитивна" << std::endl;
    }

    if (mtx.isEquivalence()) {
        std::cout << "Матриця еквівалентна" << std::endl;
    }
    else {
        std::cout << "Матриця не еквівалентна" << std::endl;
    }

    if (mtx.isPartialOrder()) {
        std::cout << "Матриця часткового порядку" << std::endl;
    }
    else {
        std::cout << "Матриця не часткового порядку" << std::endl;
    }

    if (mtx.isStrictOrder()) {
        std::cout << "Матриця строго порядку" << std::endl;
    }
    else {
        std::cout << "Матриця не строго порядку" << std::endl;
    }

    std::cout << "Транзитивне замикання:" << std::endl;

    auto test1 = mtx;

    test1.makeTransitive();

    test1.print();

    std::cout << "Рефлексивне замикання:" << std::endl;

    auto test2 = mtx;

    test2.makeReflexive();

    test2.print();

    std::cout << "Симетричне замикання:" << std::endl;

    auto test3 = mtx;

    test3.makeSymmetric();

    test3.print();
    
    std::cout << std::endl;

    std::cout << "Друга степінь відношення:" << std::endl;

    auto power2 = mtx ^ 2;

    power2.print();

    return 0;
}