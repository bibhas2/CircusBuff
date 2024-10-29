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

int main()
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
