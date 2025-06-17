// Lab 09 - Templates
// Combine the following four "divide" functions into a templated function
// with any necessary specializations to handle different operations.

#include<iostream>
/*
int divide(int x, int y)
{
    return x / y;
}

float divide(float x, float y)
{
    return x / y;
}

double divide(double x, double y)
{
    return x / y;
}

char divide(char x, char y)
{
    return (char)((int)x / (int)y);
}

*/

template<typename T>
T divide(T x, T y)
{
    return x / y;
}

template<typename T>
int divideAscii(T x, T y) 
{
    return static_cast<T>(static_cast<int>(x) / static_cast<int>(y)); // For char division
}  //static_cast is used to convert types safely and performs type checking at compile time

int main()
{
    std::cout << "Let's divide some things!\n";
    std::cout << "12 / 6 = " << divide(12, 6) << "\n";
    std::cout << "3.5 / 1.2 = " << divide(3.5, 1.2) << "\n";
    std::cout << "0.0007 / 0.0000001 = " << divide(0.0007, 0.0000001) << "\n";
    std::cout << "z / $ = " << divideAscii('z', '$') << "\n\n";
    return 0;
}