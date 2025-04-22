#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio> // for printf

using namespace std;

// Person struct definition
struct Person {
    string ssnLast4;
    string firstName;
    string lastName;
    string email;
};

// Function to read person data from file
vector<Person> readPerson(ifstream& inFile) {
    vector<Person> people;
    Person tempPerson;
    
    while (inFile >> tempPerson.ssnLast4 >> tempPerson.firstName 
                 >> tempPerson.lastName >> tempPerson.email) {
        people.push_back(tempPerson);
    }
    
    return people;
}

int main() {
    // Open the input file stream
    ifstream inFile("persons.txt");
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    
    // Read person data into a vector
    vector<Person> people = readPerson(inFile);
    inFile.close();
    
    // Loop through and print each person
    for (const Person& p : people) {
        // Convert first and last names to uppercase for output
        string upperLast = p.lastName;
        string upperFirst = p.firstName;
        for (char& c : upperLast) c = toupper(c);
        for (char& c : upperFirst) c = toupper(c);
        
        // Print in required format using printf
        printf("%s, %s:%s:%s\n", 
               upperLast.c_str(), 
               upperFirst.c_str(), 
               p.ssnLast4.c_str(), 
               p.email.c_str());
    }
    
    return 0;
}