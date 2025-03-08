// C++ Mathmatical operators
#include <iostream>
using namespace std;
int main()
{
    int first_number, second_number;
    cout << "Enter the first number: ";
    cin >> first_number;
    cout << "Enter the second number: ";
    cin >> second_number;

    // Addition with +
    cout << first_number << " + " << second_number << " = " << first_number + second_number << endl;
    // Subtraction with -
    cout << first_number << " - " << second_number << " = " << first_number - second_number << endl;
    // Multiplication with *
    cout << first_number << " * " << second_number << " = " << first_number * second_number << endl;
    // Division with /
    cout << first_number << " / " << second_number << " = " << first_number / second_number << endl;
    // Modulus with %
    cout << first_number << " % " << second_number << " = " << first_number % second_number << endl;
    return 0;
}