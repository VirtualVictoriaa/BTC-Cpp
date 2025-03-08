#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main () {
    int numberToGuess, numberGuessed, numberOfGuesses=0;

// initialize random number
    srand(time(NULL));
    numberToGuess = rand() % 10 + 1;
    cout << "Guess a number between 1 and 10: ";
    do {
        cin >> numberGuessed;
        numberOfGuesses++;
        if (numberGuessed < numberToGuess) {
            cout << "Higher. Try again: ";
        } else if (numberGuessed > numberToGuess) {
            cout << "Lower. Try again: ";
        } else {
            cout << "Congratulations! You guessed the number in " << numberOfGuesses << " tries.\n";
            return 0;
        }
    } while (numberOfGuesses < 3);

    cout << "Sorry, you've used all your tries. The number was " << numberToGuess << ".\n";
    return 0;
}