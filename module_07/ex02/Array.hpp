#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array {
private:
    T* elements;
    unsigned int _size;

public:
    Array() : elements(NULL), _size(0) {}

    Array(unsigned int n) : _size(n) {
        elements = new T[_size];
        for (unsigned int i = 0; i < _size; ++i) {
            elements[i] = T();
        }
    }

    Array(const Array& other) : _size(other._size) {
        elements = new T[_size];
        for (unsigned int i = 0; i < _size; ++i) {
            elements[i] = other.elements[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] elements;

            _size = other._size;

            elements = new T[_size];
            for (unsigned int i = 0; i < _size; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    ~Array() {
        delete[] elements;
    }

    T& operator[](unsigned int index){
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    const T& operator[](unsigned int index) const {
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

    unsigned int size() const {
        return _size;
    }
};

#endif
