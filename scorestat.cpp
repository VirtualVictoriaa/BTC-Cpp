#include <iostream>
#include <string>
using namespace std;

int main() {
    const int ARRAY_LEN = 5;                          // Number of elements in array
    string names[ARRAY_LEN];                          // Array of names
    int scores[ARRAY_LEN];                            // Array of test scores
    int sum = 0;                                      // Sum of all test scores
    int maxScore = 0;                                 // Maximum test score
    int minScore = 100;                               // Minimum test score
    string maxName, minName;                          // Names associated with max and min scores

    // Read names and scores from the user
    cout << "Enter " << ARRAY_LEN << " names and test scores:" << endl;
    for (int i = 0; i < ARRAY_LEN; i++) {
        cout << "Name " << (i + 1) << ": ";
        cin >> names[i];
        cout << "Score " << (i + 1) << ": ";
        cin >> scores[i];
        sum += scores[i];
        if (scores[i] > maxScore) {                   // Find maximum score
            maxScore = scores[i];
            maxName = names[i];
        }
        if (scores[i] < minScore) {                   // Find minimum score
            minScore = scores[i];
            minName = names[i];
        }
    }

    // Calculate average
    double average = static_cast<double>(sum) / ARRAY_LEN;

    // Output results
    cout << "Maximum score: " << maxScore << " by " << maxName << endl;
    cout << "Minimum score: " << minScore << " by " << minName << endl;
    cout << "Average score: " << average << endl;

    return 0;
}