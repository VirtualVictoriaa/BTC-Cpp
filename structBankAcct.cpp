#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

const int MAX_ACCTS = 10;

struct BankAcct {
    int id;
    string name;
    float balance;

    void display() {
        cout << name << " has a balance of $" << balance << endl;
    }

    void deposit(float amount) {
        balance += amount;
    }

    void withdraw(float amount) {
        if (balance < amount) {
            cout << "Insufficient funds\n";
        } else {
            balance -= amount;
        }
    }
};

void printAccounts(BankAcct accounts[], int count) {
    float total = 0;
    cout << "ID\tAccount\tBalance\n";
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t$%.2f\n", accounts[i].id, accounts[i].name.c_str(), accounts[i].balance);
        total += accounts[i].balance;
    }
    printf("TOTAL\t\t\t$%.2f\n", total);
}

int main() {
    BankAcct accounts[MAX_ACCTS] = {
        {1, "WECU", 3.50},
        {2, "BECU", 3.50},
        {3, "Chase", 2.50},
        {4, "US Bank", 1.50}
    };
    int count = 4;  // Number of accounts
    int next_id = 5; // Next available account ID
    char selection;

    try {
        do {
            printAccounts(accounts, count);
            cout << "(D) Deposit, (W) Withdraw, (A) Add Account, (Q) Quit: ";
            cin >> selection;

            switch (selection) {
                case 'D':
                case 'd': {                               // Deposit case
                    cout << "Deposit\n";
                    cout << "Enter account id: ";
                    int id;
                    cin >> id;
                    cout << "Enter deposit amount: ";
                    float amount;                         // Deposit amount variable float
                    cin >> amount;

                    bool found = false;                   // Boolean variable to check if account is found
                    for (int i = 0; i < count; i++) {     // Loop through accounts
                        if (accounts[i].id == id) {
                            accounts[i].deposit(amount);  // Deposit amount
                            found = true;
                            break;
                        }
                    }
                    if (!found) {                         // If account is not found print message
                        cout << "Account not found.\n";
                    }
                    break;
                }
                case 'W':                                 // Withdraw case
                case 'w': {
                    cout << "Withdraw\n";
                    cout << "Enter account id: ";
                    int id;
                    cin >> id;
                    cout << "Enter withdrawal amount: ";
                    float amount;
                    cin >> amount;

                    bool found = false;
                    for (int i = 0; i < count; i++) {     // Loop through accounts
                        if (accounts[i].id == id) {
                            accounts[i].withdraw(amount); // Withdraw amount
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Account not found.\n";
                    }
                    break;
                }
                case 'A':
                case 'a': {
                    if (count == MAX_ACCTS) {           // Check if maximum number of accounts is reached
                        cout << "Maximum number of accounts reached. Cannot add more.\n";
                        continue;
                    }
                    else if (count > MAX_ACCTS) {       // Check if maximum number of accounts is exceeded
                        throw(std::runtime_error( "What are you trying to do? Overload my memory? See ya!"));
                    }

                    string name;
                    float balance;
                    cout << "Enter account name: ";
                    cin >> name;
                    cout << "Enter initial balance: ";
                    cin >> balance;

                    accounts[count] = {next_id++, name, balance};
                    count++;
                    break;
                }
                case 'Q':
                case 'q':
                    cout << "Goodbye!\n";
                    break;
                default:
                    cout << "Invalid selection\n";
            }
        } while (selection != 'Q' && selection != 'q');
    } catch (const std::runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}