#include <vector>
#include <iostream>

namespace helper {
    template<typename T>
    class iterator {
    private:
        using iterator_type = std::vector<std::vector<T>>::iterator;
        iterator_type iter;

    public:
        iterator(iterator_type it) : iter(it) {}

        bool operator!=(const iterator& other) const {
            return iter != other.iter;
        }

        iterator& operator++() {
            ++iter;
            return *this;
        }

        std::vector<T>& operator*() {
            return *iter;
        }
    };
}