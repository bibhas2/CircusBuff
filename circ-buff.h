#pragma once
#include <stdexcept>

template <size_t CAPACITY, class T>
struct CircBuff {
	T data[CAPACITY];
	size_t start = 0;
	size_t capacity = CAPACITY;
	size_t size = 0;

    void add(const T& value) {
        if (size < capacity) {
            ++size;

            data[size - 1] = value;
        }
        else {
            size_t index = start;

            start += 1;

            start = start % capacity;

            data[index] = value;
        }
    }

    T& at(size_t pos) {
        if (pos >= size) {
            throw std::out_of_range("Given index is outside the size of.");
        }

        size_t i = start + pos;

        i = i % capacity;

        return data[i];
    }
};