#include "Matrix.h"

class boolMatrix {
private:
	std::unique_ptr<matrix<bool>> _matrix;
	size_t size;

public:
	template<typename T>
	boolMatrix(matrix<T>* _mtx) {
		_matrix = std::make_unique<matrix<bool>>();
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

	boolMatrix(boolMatrix&& other) noexcept {
		_matrix = std::move(other._matrix);
		size = other.size;
		other.size = 0;
	}

	boolMatrix(const boolMatrix& other) {
		// Copy the size
		this->size = other.size;

		// Create a new matrix and copy the content from the source matrix
		_matrix = std::make_unique<matrix<bool>>();
		_matrix->resize(other._matrix->size().first, other._matrix->size().second);

		for (int i = 0; i < other._matrix->size().first; i++) {
			for (int j = 0; j < other._matrix->size().second; j++) {
				(*_matrix)[i][j] = (*other._matrix)[i][j];
			}
		}
	}

	boolMatrix operator^(const int power) const {
		boolMatrix result(_matrix.get());

		for (int p = 1; p < power; ++p) {
			boolMatrix temp(result._matrix.get());

			for (int i = 0; i < size; ++i) {
				for (int j = 0; j < size; ++j) {
					bool value = true;
					for (int k = 0; k < size; ++k) {
						value = value || ((*_matrix)[i][k] && (*temp._matrix)[k][j]);
					}
					(*result._matrix)[i][j] = value;
				}
			}
		}

		return result;
	}

	void makeReflexive() {
		for (int i = 0; i < size; i++) {
			if (!(*_matrix)[i][i]) {
				(*_matrix)[i][i] = 1;
			}
		}
	}

	void makeSymmetric() {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if ((*_matrix)[i][j] != (*_matrix)[j][i]) {
					(*_matrix)[i][j] = (*_matrix)[j][i];
				}
			}
		}
	}

	void makeTransitive() {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				for (int k = 0; k < size; ++k) {
					if ((*_matrix)[i][j] && (*_matrix)[j][k] && !(*_matrix)[i][k]) {
						(*_matrix)[i][k] = true;
					}
				}
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