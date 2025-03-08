//Lab 4 Custom Function

#include <iostream>
using namespace std;

char getLetterGrade(int score, int curve);

int main()
{
    // Declare variables for score and curve
    int score, curve;
    cout << "Enter the number grade: ";
    cin >> score;
    cout << "Enter the curve percentage(%): ";
    cin >> curve;
    // Call the function and display the result
    char letterGrade = getLetterGrade(score, curve);
    cout << "The letter grade is: " << letterGrade << endl;

    return 0;
}
// Function to calculate the letter grade based on score and curve
char getLetterGrade(int score, int curve)
{
    int curvedScore = score + (score * curve / 100);

    if (curvedScore >= 90)
        return 'A';
    else if (curvedScore >= 80)
        return 'B';
    else if (curvedScore >= 70)
        return 'C';
    else if (curvedScore >= 60)
        return 'D';
    else
        return 'F';
}