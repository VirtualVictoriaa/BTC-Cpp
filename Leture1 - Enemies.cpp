// Leture1 - Enemies.cpp

#include <iostream> // console stream
#include <fstream>  // file stream
#include <sstream>  // string stream
#include <string>
#include <vector>

using namespace std;

struct Enemy {
    int id;
    string name;
    string desc;
    int health;
};

// printEnemy: takes an Enemy by reference and displays it's properies
void printEnemy(Enemy& e) {
    printf("ID: %d\nNAME: %s\nDESC: %s\nHEALTH: %d\n\n", 
        e.id, e.name.c_str(), e.desc.c_str(), e.health);
}

// enemy data file path
const string enemies_file_path = "C:\\app\\enemies.txt";

int main()
{
    // initialize the file stream
    ifstream input_file;
    input_file.open(enemies_file_path);

    // create variables to store lines and columns from the tsv file
    string line;
    string col;

    // a vector to hold the Enemies
    vector<Enemy> enemies;

    // loop through each line in the file (splits file by \n)
    while (getline(input_file, line)) {

        // convert each line into a stringstream 
        // so that we can use getline on it and specify a "delimiter"
        stringstream input_string(line);

        // individual Enemy that we will build from each line
        Enemy e;

        // iterator to track what column we're reading from (ie 0:ID, 1:NAME, etc)
        int i = 0;

        // break up the line by tab '\t' and put the data into the Enemy struct
        while (getline(input_string, col, '\t')) {
            switch (i) {
            case 0:
                e.id = stoi(col);
                break;
            case 1:
                e.name = col;
                break;
            case 2:
                e.desc = col;
                break;
            case 3:
                e.health = stoi(col);
                break;
            }
            i++;
        }

        // add the finished Enemy to the enemies vector
        enemies.push_back(e);
    }

    // foreach loop
    for (Enemy& e : enemies) {
        // print the Enemy data
        printEnemy(e);
    }

    return 0;
}
