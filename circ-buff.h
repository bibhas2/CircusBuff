#pragma once
#include <stdexcept>

template <size_t CAPACITY, class T>
struct CircBuff {
	T data[CAPACITY];
	size_t start = 0;
	size_t capacity = CAPACITY;
	size_t size = 0;
    size_t end = 0;

    void add(const T& value) {
        //Set value at the current end position
        data[end] = value;

        if (size < capacity) {
            //Grow size
            ++size;
        }

        //Move end forward
        end = (end + 1) % capacity;

        if (size == capacity) {
            //At full capacity start and end
            //must coincide
            start = end;
        }
    }

    T& at(size_t pos) {
        if (pos >= size) {
            throw std::out_of_range("Index is outside the size of buffer.");
        }

        size_t i = start + pos;

        i = i % capacity;

        return data[i];
    }
};