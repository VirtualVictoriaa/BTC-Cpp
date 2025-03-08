#include <iostream>
#include <string>
using namespace std;
int main()
{
    string userNum;// Declare a string to store the user input
    int sum = 0;// Initialize the sum to 0
    do {
        cout << "Enter a number: ";// Prompt the user for a number
        cin >> userNum;
        int num = stoi(userNum); // Convert the input string to an integer
        sum += num; // Add the number to the running tota
    } while (userNum != "0");// Continue the loop until the user enters 0
    cout << "The total sum is: " << sum << endl; // Output the total sum
    return 0;
}