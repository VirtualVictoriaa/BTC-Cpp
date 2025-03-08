//Lab 2 Grade Translator with Challenge

#include <iostream>
using namespace std;
int main()
{
    int testScore;
    cout << "Enter your test score: ";
    cin >> testScore;
    switch (testScore) {
        case 90 ... 100:
            cout << "Your grade is an A.\n";
            break;
        case 80 ... 89:
            cout << "Your grade is a B.\n";
            break;
        case 70 ... 79:
            cout << "Your grade is a C.\n";
            break;
        case 60 ... 69:
            cout << "Your grade is a D.\n";
            break;
        case 1 ... 59:
            cout << "Your grade is an F.\n";
            break;
        default:
            cout << "That isn't in our grading system. Do you even go here?\n";
            break;
    }
}