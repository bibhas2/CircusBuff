// CircusBuff.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "circ-buff.h"


template <size_t CAPACITY, class T>
void print_buff(CircBuff<CAPACITY, T>& buff) {
    std::cout << "[";

    for (size_t i = 0; i < buff.size; ++i) {
        if (i > 0) {
            std::cout << ", ";
        }

        std::cout << buff.at(i);
    }

    std::cout << "]" << std::endl;
}

void test_take() {
    CircBuff<4, int> buff;

    buff.add(0);
    std::cout << "Taking: " << buff.take() << std::endl;
    print_buff(buff);

    buff.add(0);
    buff.add(1);
    buff.add(2);
    std::cout << "Taking: " << buff.take() << std::endl;
    print_buff(buff);

    buff.clear();
    buff.add(0);
    buff.add(1);
    buff.add(2);
    buff.add(3);
    std::cout << "Taking: " << buff.take() << std::endl;
    std::cout << "Taking: " << buff.take() << std::endl;
    std::cout << "Taking: " << buff.take() << std::endl;
    std::cout << "Taking: " << buff.take() << std::endl;
    print_buff(buff);

    buff.clear();
    buff.add(0);
    buff.add(1);
    buff.add(2);
    buff.add(3);
    buff.add(4);
    buff.add(5);
    std::cout << "Taking: " << buff.take() << std::endl;
    std::cout << "Taking: " << buff.take() << std::endl;
    std::cout << "Taking: " << buff.take() << std::endl;
    std::cout << "Taking: " << buff.take() << std::endl;
    print_buff(buff);

}

void test_add()
{
    CircBuff<4, int> buff;

    print_buff(buff);

    buff.add(0);
    print_buff(buff);

    buff.add(1);
    print_buff(buff);

    buff.add(2);
    print_buff(buff);

    buff.add(3);
    print_buff(buff);

    buff.add(4);
    print_buff(buff);

    buff.add(5);
    print_buff(buff);

    buff.add(6);
    print_buff(buff);

    buff.add(7);
    print_buff(buff);

    buff.add(8);
    print_buff(buff);
}

int main() {
    test_take();
}