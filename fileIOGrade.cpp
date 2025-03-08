#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

//const string FILE_PATH = "home/ratking/Projects/BTC/";
const string FILE_NAME = "grades.txt";
// Function to calculate the grade based on the score
char calculateGrade(int score) {
    char grade;
    grade = 70 - (2 * (score / 60) + score / 70 + score / 80 + score / 90);
    return grade;
}

bool isdigit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    ifstream inFile;
    ofstream outFile;
    string data, line;
    int columns, row, score;
    char c, grade;

    // Concatenate FILE_PATH and FILE_NAME to get the full file path
    //string fullFilePath = FILE_PATH + FILE_NAME;

    inFile.open(FILE_NAME);
    if (inFile.fail()) {
        cout << "ERROR: File " << FILE_NAME << " does not exsist in time or space\n";
        exit(1);
    }

    row = 0;
    while (getline(inFile, line)) {
        if (row == 0) { //Skip header
            row++;
            continue;
        }
        columns=0;
        //cout << line << endl;
        stringstream lineStream = stringstream(line);
        while (getline(lineStream, data, ' ')) {
            if (columns == 1) { //Only print second column
                score = stoi(data);
                grade = calculateGrade(score); // Get letter grade
                cout << data << ": " << grade;
            }
            if (columns == 0) {
                //Gets name from first column
                cout << data << " ";
            }
            columns++;
        }
        cout << "\n\n";
    }
    return 0;
}