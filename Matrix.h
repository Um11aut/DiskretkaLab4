#pragma once
#include "math_helper.hpp"

#include <vector>
#include <iostream>
#include <memory>

template<typename Type>
class matrix {
private:
    std::unique_ptr<std::vector<std::vector<Type>>> _matrix = std::make_unique<std::vector<std::vector<Type>>>();
    int rows, cols;

public:
    matrix(int n, int m) {
        resize(n, m);
    }

    matrix() = default;

    template<typename MoveType>
    matrix(matrix<MoveType>&& other) {
        this->_matrix = std::move(other._matrix);
        
        this->rows = other.rows;
        this->cols = other.cols;
    }

    void print() {
        for (int i = 0; i < this->size().first; i++) {
            for (int j = 0; j < this->size().second; j++) {
                std::cout << (*_matrix)[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void resize(int n, int m) {
        _matrix->resize(n, std::vector<Type>(m));

        this->rows = n;
        this->cols = m;
    }

    std::pair<int, int> size() const {
        return std::pair<int, int>(rows, cols);
    }

    template<typename... Values>
    void fill(Values&&... vals) {
        fillHelper(0, 0, std::forward<Values>(vals)...);
    }

    typename std::vector<Type>::iterator begin() {
        return _matrix->begin();
    }

    typename std::vector<Type>::iterator end() {
        return _matrix->end();
    }

    const std::vector<Type>& operator[](int index) const {
        return (*_matrix)[index];
    }

    std::vector<Type>& operator[](int index) {
        return (*_matrix)[index];
    }

private:
    template<typename T, typename... Values>
    void fillHelper(int row, int col, T&& val, Values&&... rest) {
        (*_matrix)[row][col] = std::forward<T>(val);

        if (++col == (*_matrix)[0].size()) {
            col = 0;
            ++row;
        }

        if constexpr (sizeof...(rest) > 0) {
            fillHelper(row, col, std::forward<Values>(rest)...);
        }
    }
};