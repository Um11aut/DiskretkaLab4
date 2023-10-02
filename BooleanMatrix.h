#pragma once
#include "Matrix.h"

class boolMatrix {
private:
	std::unique_ptr<matrix<bool>> _matrix = std::make_unique<matrix<bool>>();
	int size;

public:
	template<typename T>
	boolMatrix(matrix<T>* _mtx) {
		_matrix->resize(_mtx->size().first, _mtx->size().second);
		if (_matrix->size().first == _matrix->size().second) {
			this->size = _matrix->size().first;
		}

		for (int i = 0; i < _mtx->size().first; i++) {
			for (int j = 0; j < _mtx->size().second; j++) {
				(*_matrix)[i][j] = (*_mtx)[i][j];
			}
		}
	}

	void print() {
		for (int i = 0; i < _matrix->size().first; i++) {
			for (int j = 0; j < _matrix->size().second; j++) {
				std::cout << (*_matrix)[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	// Перевірка чи є відношення еквівалентності
	bool isEquivalence() const {
		// Перевірка рефлексивності, симетричності та транзитивності
		return isReflexive() && isSymmetric() && isTransitive();
	}

	// Перевірка чи є відношення частковим порядком
	bool isPartialOrder() const {
		// Перевірка рефлексивності, антисиметричності та транзитивності
		return isReflexive() && isAntisymmetric() && isTransitive();
	}

	bool isStrictOrder() const {
		// Перевірка антисиметричності та транзитивності
		return isAntisymmetric() && isTransitive();
	}

	bool isReflexive() const {
		std::cout << std::endl;
		for (int i = 0; i < size; i++) {
			if (!(*_matrix)[i][i]) {
				return false;
			}
		}
		return true;
	}

	bool isSymmetric() const {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if ((*_matrix)[i][j] != (*_matrix)[j][i]) {
					return false;
				}
			}
		}
		return true;
	}

	bool isAntisymmetric() const {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (i != j && (*_matrix)[i][j] && (*_matrix)[j][i]) {
					return false;
				}
			}
		}
		return true;
	}


	bool isTransitive() const {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				for (int k = 0; k < size; ++k) {
					if ((*_matrix)[i][j] && (*_matrix)[j][k] && !(*_matrix)[i][k]) {
						return false;
					}
				}
			}
		}
		return true;
	}
};