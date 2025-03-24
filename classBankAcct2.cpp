#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

const int MAX_ACCTS = 10;

class BankAcct {
private:
    int id;
    string name;
    float balance;

public:
    // Constructors
    BankAcct() : id(0), name("Unnamed"), balance(0.0f) {} // Default constructor
    BankAcct(int id, string name, float balance) : id(id), name(name), balance(balance) {}

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    float getBalance() const { return balance; }

    // Setters
    void setId(int newId) { id = newId; }
    void setName(const string& newName) { name = newName; }
    void setBalance(float newBalance) { balance = newBalance; }

    // Member functions
    void display() const {
        cout << name << " has a balance of $";
        cout << static_cast<int>(balance) << "." 
             << static_cast<int>((balance - static_cast<int>(balance)) * 100 + 0.5) << endl;
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

// Function to print all accounts
void printAccounts(BankAcct accounts[], int count) {
    float total = 0;
    cout << "ID\tAccount\t\tBalance\n";
    for (int i = 0; i < count; i++) {
        cout << accounts[i].getId() << "\t" << accounts[i].getName() << "\t\t$";
        cout << static_cast<int>(accounts[i].getBalance()) << "." 
             << static_cast<int>((accounts[i].getBalance() - static_cast<int>(accounts[i].getBalance())) * 100 + 0.5) << endl;
        total += accounts[i].getBalance();
    }
    cout << "TOTAL\t\t\t$";
    cout << static_cast<int>(total) << "." 
         << static_cast<int>((total - static_cast<int>(total)) * 100 + 0.5) << endl;
}

int main() {
    BankAcct accounts[MAX_ACCTS] = {};                    // Array of BankAcct objects
    accounts[0] = BankAcct(1, "WECU", 3.50);
    accounts[1] = BankAcct(2, "BECU", 3.50);
    accounts[2] = BankAcct(3, "Chase", 2.50);
    accounts[3] = BankAcct(4, "US Bank", 1.50);

    int count = 4;                                       // Number of accounts
    int next_id = 5;                                     // Next available account ID
    char selection;

    try {
        do {
            printAccounts(accounts, count);              // Print all accounts
            cout << "(D) Deposit, (W) Withdraw, (T) Transfer, (A) Add Account, (R) Remove Account, (Q) Quit: ";
            cin >> selection;

            switch (selection) {
                case 'D':
                case 'd': {                              // Deposit case
                    cout << "Deposit\n";
                    cout << "Enter account id: ";
                    int id;
                    cin >> id;
                    cout << "Enter deposit amount: ";
                    float amount;
                    cin >> amount;

                    bool found = false;
                    for (int i = 0; i < count; i++) {
                        if (accounts[i].getId() == id) {
                            accounts[i].deposit(amount);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Account not found.\n";
                    }
                    break;
                }
                case 'W':
                case 'w': {                               // Withdraw case
                    cout << "Withdraw\n";
                    cout << "Enter account id: ";
                    int id;
                    cin >> id;
                    cout << "Enter withdrawal amount: ";
                    float amount;
                    cin >> amount;

                    bool found = false;
                    for (int i = 0; i < count; i++) {
                        if (accounts[i].getId() == id) {
                            accounts[i].withdraw(amount);
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
                case 'a': {                               // Add Account case
                    if (count == MAX_ACCTS) {
                        cout << "Maximum number of accounts reached. Cannot add more.\n";
                        continue;
                    }

                    string name;
                    float balance;
                    cout << "Enter account name: ";
                    cin >> name;
                    cout << "Enter initial balance: ";
                    cin >> balance;

                    accounts[count] = BankAcct(next_id++, name, balance);
                    count++;
                    break;
                }
                case 'R':
                case 'r': {                               // Remove Account case
                    cout << "Remove\n";
                    cout << "Enter account id to remove: ";
                    int id;
                    cin >> id;

                    bool found = false;
                    for (int i = 0; i < count; i++) {
                        if (accounts[i].getId() == id) {
                            for (int j = i; j < count - 1; j++) {
                                accounts[j] = accounts[j + 1];
                            }
                            count--;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Account not found.\n";
                    }
                    break;
                }
                case 'T':
                case 't': {                               // Transfer case
                    cout << "Transfer\n";
                    cout << "Enter account id to transfer from: ";
                    int idFrom;
                    cin >> idFrom;
                    cout << "Enter account id to transfer to: ";
                    int idTo;
                    cin >> idTo;
                    cout << "Enter transfer amount: ";
                    float amount;
                    cin >> amount;

                    bool fromFound = false, toFound = false;
                    for (int i = 0; i < count; i++) {
                        if (accounts[i].getId() == idFrom) {
                            accounts[i].withdraw(amount);
                            fromFound = true;
                        }
                        if (accounts[i].getId() == idTo) {
                            accounts[i].deposit(amount);
                            toFound = true;
                        }
                    }
                    if (!fromFound || !toFound) {
                        cout << "One or both accounts not found.\n";
                    }
                    break;
                }
                case 'Q':
                case 'q': {
                    cout << "Goodbye!\n";
                    break;
                }
                default:
                    cout << "Invalid selection\n";
            }
        } while (selection != 'Q' && selection != 'q');
    } catch (const std::runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}