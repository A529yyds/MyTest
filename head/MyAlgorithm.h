// accumulate method
#include <iostream>
struct Mul1
{
    int operator()(int a, int b)
    {
        std::cout << "a is " << a << ", b is " << b << std::endl;
        return a + (b + 1);
    }
};

struct Mul2
{
    int operator()(int a, int b)
    {
        return a + 2 * b;
    }
};

// count
bool IsOdd(int a)
{
    return ((a % 2) == 1);
}