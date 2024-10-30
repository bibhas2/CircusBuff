#pragma once
#include <stdexcept>

template <size_t CAPACITY, class T>
struct CircBuff {
	T data[CAPACITY];
	size_t start = 0;
	size_t capacity = CAPACITY;
	size_t size = 0;
    size_t end = 0;

    void stats() {
        std::cout << "Cap: " << capacity << " Start: " << start << " End: " << end << " Sz: " << size << std::endl;
    }

    void clear() {
        start = 0;
        end = 0;
        size = 0;
    }

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

    T& take() {
        if (size == 0) {
            throw std::out_of_range("Buffer is empty.");
        }

        //Get the value at the front
        T& result = at(0);

        //Shrink
        --size;

        //Move start forward
        start = (start + 1) % capacity;

        return result;
    }

    T& peek() {
        return at(0);
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