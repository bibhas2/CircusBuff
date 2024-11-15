#pragma once
#include <stdexcept>

/*
* A fixed capacity circular buffer or queue. When the buffer is full, adding
* a new value overwrites the oldest value. No heap allocation or memory copy is done.
*/
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

    /*
    * Empties out the buffer.
    */
    void clear() {
        start = 0;
        end = 0;
        size = 0;
    }

    /*
    * Adds a value to the end of the buffer. If the buffer is already
    * full capacity then this will overwrite the current first value in the buffer.
    */
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

    /*
    * Returns the first value in the buffer and removes it.
    */
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

    /*
    * Returns the current first value in the buffer without removing it.
    */
    T& peek() {
        return at(0);
    }

    /*
    * Returns a value at a given position in the buffer. The value of
    * pos must be [0, size).
    */
    T& at(size_t pos) {
        if (pos >= size) {
            throw std::out_of_range("Index is outside the size of buffer.");
        }

        size_t i = (start + pos) % capacity;

        return data[i];
    }

    bool empty() {
        return size == 0;
    }
};