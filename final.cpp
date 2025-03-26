#include <iostream>


using namespace std;
/*
int main () {
    int pizzas = 3;
    int people = 5;
    cout << "There are " << static_cast<double>(pizzas) / people << " pizzas per person." << endl;
    return 0;
    }

int main()
{
    int count = 2;
    while (count < 10)
    {
        if (count % 2 == 0)
        {
            cout << count << " ";
        }
        count++;
    }
    cout << " Who do we appreciate?\n";
    return 0;
}

int main()
{
    int number;
    cout << "Input a number: ";
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        cout << number << " ";
    }
    cout << endl;
    return 0;
}

//declare milClock here
int milClock(int hour, string period);

int main()
{
    int milHour;
    milHour = milClock(2, "PM");
    cout << "If this is right it should print 14 ... " << milHour << endl;
    return 0;
}

// define milClock here
int milClock(int hour, string period)
{
    if (period == "AM")
    {
        if (hour == 12)
        {
            return 0;
        }
        else
        {
            return hour;
        }
    }
    else
    {
        if (hour == 12)
        {
            return 12;
        }
        else
        {
            return hour + 12;
        }
    }
}

// declare intTransfer here
void intTransfer(int &num1, int &num2, int num3);

int main()
{
    int num1 = 2, num2 = 2;
    intTransfer(num1, num2, 2);
    cout << "If this is right it should print 0, 4 ... " << num1 << ", " << num2 << endl;
    system("pause");
    return 0;
}

// define intTransfer here
void intTransfer(int &num1, int &num2, int num3)
{
    num1 = num1 - num3;
    num2 = num2 + num3;
}

#include <string>
#include <fstream>

const string FILE_NAME = "numbers-1.txt";
int evenCount = 0;

int main() {
    ifstream inFile;
    ofstream outFile;
    string data, line;

    inFile.open(FILE_NAME);
    if (inFile.fail()) {
        cout << "ERROR: File " << FILE_NAME << " does not exsist in time or space\n";
        exit(1);
    }
    // Read the file and print the even numbers
    while (getline(inFile, line)) {
        if (stoi(line) % 2 == 0) {        // Check if the number is even
            evenCount++;
        }
    }
    cout << "There are " << evenCount << " even numbers in the file\n";
    return 0;
}

#include "string.h"

int main()
{
    string jedi[4] = { "Obi Wan", "Yoda", "Kit Fisto", "Luke" };
    // write the code to swap "Obi Wan" and "Yoda" here
    string temp = jedi[0];
    jedi[0] = jedi[1];
    jedi[1] = temp;
    for (int i = 0; i < 4; i++)
    {
        cout << jedi[i] << endl;
        cout << "Yoda has the high ground now\n";
    }

    return 0;
}

#include <vector>
#include "string.h"

int main()
{
    vector <string> victor = { "Earnhardt", "Allies", "Everdeen" };
    // write the code to add "Ali" to the end of victor
    victor.push_back("Ali");
    for (int i = 0; i < victor.size(); i++)
    {
        cout << victor[i] << endl;
    }
    return 0;
}

int main()
{
    int myNumber = 12;
    // declare an int pointer here
    int *point;
    // point the pointer to myNumber here
    point = &myNumber;
    // use the pointer to print myNumber here
    cout << "My number is ... " << *point << endl;
    return 0;
}

#include "string.h"

struct game {
    // fill this in
    string title;
    string type;
    int price;

};

int main()
{
    // create a "puzzle" game, titled "Sea Plus Plus" for "20" dollars
    game puzzle;
    puzzle.title = "Sea Plus Plus";
    puzzle.type = "puzzle";
    puzzle.price = 20;
    // print out the game's title
    cout << "The game is called " << puzzle.title << endl;
    cout << "Pay " << puzzle.price << " dollars to play\n";
    int paid;
    cin >> paid;
    if (paid >= puzzle.price) {
        cout << "Welcome to Sea Plus Plus!\n";
      }
      else {
        cout << "Ha, broke\n";
    }
    return 0;
}

#include "string.h"

class Drone
{
public:
    Drone(string name, int cameras);
    Drone(string name);
    Drone();
    void display();
    void move(double latitude, double longitude, int altitude);

private:
    string name;
    int cameras;
    double latitude;
    double longitude;
    int altitude;
};

int main()
{
    // construct a Drone named "Survey01" and with 2 cameras
    Drone Survey01("Survey01", 2);
    // move the Drone to latitude 48.7655, longitude -122.5105, and altitude 100
    Survey01.move(48.7655, -122.5105, 100);
    // display the Drone's information
    Survey01.display();
    return 0;
}

Drone::Drone(string n, int c)
{
    name = n;
    cameras = c;
}
Drone::Drone(string n)
{
    name = n;
    cameras = 1;
}
Drone::Drone()
{
    name = "Unidentified";
    cameras = 1;
}
void Drone::display()
{
    cout << name << "(" << cameras << ") lat " << latitude
        << ", long " << longitude << ", alt " << altitude << endl;
}
void Drone::move(double lat, double lon, int alt)
{
    latitude = lat;
    longitude = lon;
    altitude = alt;
}

class Drone
{
public:
    Drone(string name, int cameras);
    Drone(string name);
    Drone();
    void display();
    void move(double latitude, double longitude, int altitude);
    // add a function to land
    void land(int altitude);

private:
    string name;
    int cameras;
    double latitude;
    double longitude;
    int altitude;
};

int main()
{
    system("pause");
    return 0;
}

Drone::Drone(string n, int c)
{
    name = n;
    cameras = c;
}
Drone::Drone(string n)
{
    name = n;
    cameras = 1;
}
Drone::Drone()
{
    name = "Unidentified";
    cameras = 1;
}
void Drone::display()
{
    cout << name << "(" << cameras << ") lat " << latitude
        << ", long " << longitude << ", alt " << altitude << endl;
}
void Drone::move(double lat, double lon, int alt)
{
    latitude = lat;
    longitude = lon;
    altitude = alt;
}
// add a function to land
void Drone::land(int altitude)
{
    altitude = 0;
    cout << "Landing\n";
}
*/

void write_vertical(int n) {
    if (n < 10)
    {
        cout << n << endl;
    }
    else
    {
        write_vertical(n / 10);
        cout << (n % 10) << endl;
    }
}