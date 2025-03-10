#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

const int MAX_ACCTS = 10;

struct BankAcct {
    string name;
    float balance;
};

void printAccounts(BankAcct account[], int count) {
    float total = 0;
    cout << "Account\t Balance\n";
    for (int i = 0; i < count; i++) {
        printf("%s\t $%.2f\n", account[i].name.c_str(), account[i].balance);
        total += account[i].balance;
    };
    printf("TOTAL\t $%.2f\n", total);
}

int main () {
    BankAcct account[MAX_ACCTS] = {
        { "WECU", 3.50},
        { "BECU", 3.50},
        { "Chase", 2.50},
        { "Bank of America", 1.50}
    };
    int count = 4;  // number of accounts
    char selection;
    try{
    do {
        printAccounts(account, count);
        cout << "(D) Deposit, (W) Withdraw, (A) Add Account, (Q) Quit: ";
        cin >> selection;
        BankAcct newAcct;
        switch (selection) {
            case 'D':
            case 'd':
                cout << "Deposit\n";
                break;
            case 'W':
            case 'w':
                cout << "Withdraw\n";
                break;
            case 'A':
            case 'a':
                if (count == MAX_ACCTS) {
                    cout << "Why do you need more accounts? Delete an account before proceeding\n";
                    continue;
                }
                else if (count > MAX_ACCTS) {
                    throw(std::runtime_error( "What are you trying to do? Overload my memory? See ya!"));
                }
                cout << "Enter account name: ";
                cin >> newAcct.name;
                cout << "Enter initial balance: ";
                cin >> newAcct.balance;
                cout << "Add Account\n";
                account[count] = newAcct;
                count++;
                break;
            default:
                cout << "Invalid selection\n";
        }
        
    } while (selection != 'Q' && selection != 'q');
}
catch (const std::runtime_error& e) {
    cout << e.what() << endl;
}
    return 0;
}