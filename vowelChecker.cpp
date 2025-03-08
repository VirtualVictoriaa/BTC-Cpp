#include <string>
#include <iostream>
#include <cstring>
#include <inttypes.h>
#include <limits>
using namespace std;

const uint16_t LIMIT = 10; // 10 characters
const string VOWELS = "aeiou";

void printEachChar(char *uInput);

int main() {
    /*
    char uInput[LIMIT+1];
    cout << "Input up to " << LIMIT << " characters. Honor system!\n";
    cin.getline(uInput, LIMIT+1);
    cin.clear();
    fflush(stdin);
    size_t found = VOWELS.find('i', 0);
    if (found == -1) {
        cout << "Not FOUND";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "You wrote: " << uInput << "\n\n";
    */
    char uInput[LIMIT+1];
    cout << "Input up to " << LIMIT << " characters. Don't push it.\n";
    cin.getline(uInput, LIMIT+1);
    cin.clear();
    fflush(stdin);
    printEachChar(uInput);
    bool vowelFound = false;
    for (int i = 0; i < strlen(uInput); i++) {
        if (VOWELS.find(uInput[i]) != string::npos) {
            cout << "Vowel found at position " << i << endl;
            vowelFound = true;
        }
        else {
            cout << "No vowels found in the string.\n";
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "You entered: " << uInput << endl;
}

void printEachChar(char *uInput) {
    for (int i = 0; i < strlen(uInput); i++) {
        cout << uInput[i]<< endl;
    }
}