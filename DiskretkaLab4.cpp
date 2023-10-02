#include "BooleanMatrix.h"


int main() {
    matrix<int> myMatrix(5, 5);
    myMatrix.fill(
        1,0,1,0,1,
        1,1,1,1,0,
        0,0,1,1,0,
        1,1,1,1,1,
        1,0,1,1,1
    );

    myMatrix.print();

    std::cout << std::endl;

    boolMatrix mtx(&myMatrix);
    mtx.print();

    std::cout << mtx.isReflexive() << std::endl;
    std::cout << mtx.isAntisymmetric() << std::endl;
    std::cout << mtx.isTransitive() << std::endl;

    return 0;
}