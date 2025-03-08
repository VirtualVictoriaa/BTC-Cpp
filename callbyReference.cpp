#include <iostream>
using namespace std;

// amount of change to return in cents ie $2.37, amount = 237
void makeChange(int& dollars, int& quarters, int& dimes, int& nickels, int& pennies, int cents);

int main()
{
    int dollars, quarters, dimes, nickels, pennies;
    double money = 5.95;
    double cost = 4.58;
    int cents = int((money - cost) * 100);
    
    makeChange(dollars, quarters, dimes, nickels, pennies, cents);
    
    cout << "Dollars: " << dollars << endl;
    cout << "Quarters: " << quarters << endl;
    cout << "Dimes: " << dimes << endl;
    cout << "Nickels: " << nickels << endl;
    cout << "Pennies: " << pennies << endl;

    return 0;
}

//definitions
void makeChange(int& dollars, int& quarters, int& dimes, int& nickels, int& pennies, int cents) {
    dollars = cents / 100;
    cents %= 100;
    quarters = cents / 25;
    cents %= 25;
    dimes = cents / 10;
    cents %= 10;
    nickels = cents / 5;
    cents %= 5;
    pennies = cents; // Assign remaining cents to pennies
}