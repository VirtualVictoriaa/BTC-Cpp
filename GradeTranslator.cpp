//Lab 2 Grade Translator

#include <iostream>
using namespace std;
int main()
{
   /*-- int testScore;
    cout << "Enter your test score: ";
    cin >> testScore;
    if (testScore >= 90)
        cout << "Your grade is an A.\n";
    else if (testScore >= 80)
        cout << "Your grade is a B.\n";
    else if (testScore >= 70)
        cout << "Your grade is a C.\n";
    else if (testScore >= 60)
        cout << "Your grade is a D.\n";
    else
        cout << "Your grade is an F.\n";*/
    char g, m;
    int s, p;

    //F-> 70, A -> 65
    for (s = 59; s <= 100; s++) {
        g= 70 - (2 * (s / 60) + s / 70 + s / 80 + s / 90);
        p = s % 10;
        //" " 32, "-" 45, "+" 43
        m = 32 + 11 * ((p / 7) );
        cout << "Score: " << s << " Grade: " << g << endl;
    }
}