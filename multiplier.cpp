// Lab 1 - Multiplier
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    // User enters the first number
    cout << "Enter the first number: ";
    cin >> a;
    // User enters the second number
    cout << "Enter the second number: ";
    cin >> b;
    // User enters the third number
    cout << "Enter the third number: ";
    cin >> c;
    // Output the result of the multiplication and addition
    cout << a << " * " << b << " + " << c << " = " << a * b + c << endl;
    return 0;
}