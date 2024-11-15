# A Non-allocating Circular Buffer in C++

This is a circular buffer or queue. It has a fixed maximum capacity. If the queue is at full capacity and you add a new item to the end, the oldest item from the front is evicted. The queue never stops accepting items.

This implementation doesn't allocate on the heap and doesn't do any mem copy.

## Basic Usage

```c++
#include "circ-buff.h"

void test_add()
{
    CircBuff<4, int> buff;

    buff.add(1);
    buff.add(2);
    buff.add(3);
    buff.add(4);
    buff.add(5);
    buff.add(6);

    int i = buff.take(); //i should be 3
    int& j = buff.take(); //j should be 4
}
```

## Iteration
I have not added any iterator interface to this. You can loop through the items from front to back like this.

```c++
template <size_t CAPACITY, class T>
void print_buff(CircBuff<CAPACITY, T>& buff) {
    for (size_t i = 0; i < buff.size; ++i) {
        std::cout << buff.at(i) << " ";
    }

    std::cout << std::endl;
}
```

For more details, [please read my blog](https://mobiarch.wordpress.com/2024/11/15/non-allocating-circular-buffer-in-c/) on this.
