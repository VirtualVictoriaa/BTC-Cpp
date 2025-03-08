/*#include <iostream>

using namespace std;

int main()
{
    int quantity = 3;
    int price = 1.50;
    cout << "The total cost is " << (quantity * price) << endl;
    //system("pause");
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int num1 = 3, num2 = 4;
    if (num1 == num2)
    {
        cout << "They are equal." << endl;
    }
    else
    {
        cout << "They are not equal." << endl;
    }
    //system("pause");
    return 0;
} 

#include <iostream>

using namespace std;

int main()
{
    int score = 70;

    if (score >= 90)
    {
        cout << "A" << endl;
    }
    else if (score >= 80)
    {
        cout << "B" << endl;
    }
    else if (score >= 70)
    {
        cout << "C" << endl;
    }
    else if (score >= 60)
    {
        cout << "D" << endl;
    }
    else
    {
        cout << "F" << endl;
    }
    //system("pause");
    return 0;
} 

#include <iostream>

using namespace std;

int main()
{
    int score;

    cout << "Input grade: ";

    cin >> score;

    if (score >= 90)
    {
        cout << "A" << endl;
    }
    if (score >= 80)
    {
        cout << "B" << endl;
    }
    if (score >= 70)
    {
        cout << "C" << endl;
    }
    if (score >= 60)
    {
        cout << "D" << endl;
    }
    else
    {
        cout << "F" << endl;
    }
    //system("pause");
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int count = 2;

    // Cheer loop
    while (count != 9)
    {
        cout << count << " ";
        count += 2;
    }
    cout << "\nWho do we appreciate?\n";
    //system("pause");
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int number;

    cout << "Number: ";

    cin >> number;

    cout << number << endl;

    system("pause");
    return 0;
} 

#include <iostream>

using namespace std;

int main()
{
    int count = 5;

    for (count = 5; count >= 0; count--)
    {
        cout << count << " ";
    }
    cout << "\nBlastoff!\n";

    //system("pause");
    return 0;
} 

#include <iostream>
#include <string>

using namespace std;

int getNumberOfSides(string shape);

int main()
{
    int numSides;
    string shape;

    cout << "Input a shape (Triangle, Square, or Hexagon): ";

    cin >> shape;

    // implement getNumberOfSides
    numSides = getNumberOfSides(shape);

    cout << "A " << shape << " has " << numSides << " sides. Now you know!\n";

    system("pause");
    return 0;
}

int getNumberOfSides(string shape)
{
    if (shape == "Triangle")
    {
        return 3;
    }
    else if (shape == "Square")
    {
        return 4;
    }
    else if (shape == "Hexagon")
    {
        return 6;
    }
    else
    {
        return 0;
    }
} 

#include <iostream>
using namespace std;
void doubleThis(int& num);

int main()
{
    int num;

    cout << "Input number: ";

    cin >> num;

    // implement doubleThis as a Call By Reference function
    doubleThis(num);

    cout << "x2=" << num << "\n";

    system("pause");
    return 0;
}

void doubleThis (int& num) {
    num *= 2;
} */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("numbers.txt");
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    int count = 0;
    int sum = 0;
    int number;

    while (inputFile >> number) {
        count++;
        sum += number;
    }
    inputFile.close();

    double average = 0;
    if (count > 0) {
        average = sum / (double)count;
    }

    cout << "Total count of numbers: " << count << endl;
    cout << "Total sum of numbers: " << sum << endl;
    cout << "Average of numbers: " << average << endl;

    return 0;
}