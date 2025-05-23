#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract Character class
class Character {
public:
    virtual void print() = 0; // Pure virtual function to print details
    virtual string getSecretIdentity() = 0; // Pure virtual function to get realName
    virtual ~Character() {} // Virtual destructor
};

// Person class
class Person {
public:
    string realName;
    string jobTitle;

    Person(string realName, string jobTitle) {
        this->realName = realName;
        this->jobTitle = jobTitle;
    }
};

// Hero class
class Hero : public Character, public Person {
public:
    string name;
    vector<string> superPowers;
    string weakness;

    Hero(string realName, string jobTitle, string name, vector<string> superPowers, string weakness)
        : Person(realName, jobTitle) {
        this->name = name;
        this->superPowers = superPowers;
        this->weakness = weakness;
    }

    void print() override {
        cout << "Hero's Secret Identity:" << endl;
        cout << "Real Name: " << realName << endl;
        cout << "Job Title: " << jobTitle << endl;
        cout << endl;
        cout << "But you know them as...\n" << name << endl;
        cout << "Super Powers: ";
        for (const string& power : superPowers) {
            cout << power << " ";
        }
        cout << endl;
        cout << "Weakness: " << weakness << endl;
    }

    string getSecretIdentity() override {
        return realName;
    }
};

// Villain class
class Villain : public Character, public Person {
public:
    string name;
    vector<string> superPowers;
    string weakness;

    Villain(string realName, string jobTitle, string name, vector<string> superPowers, string weakness)
        : Person(realName, jobTitle) {
        this->name = name;
        this->superPowers = superPowers;
        this->weakness = weakness;
    }

    void print() override {
        cout << "Villain's Somewhat Secret Identity:" << endl;
        cout << "Real Name: " << realName << endl;
        cout << "Job Title: " << jobTitle << endl;
        cout << endl;
        cout << "But you know them as...\n" << name << endl;
        cout << "Super Powers: ";
        for (const string& power : superPowers) {
            cout << power << " ";
        }
        cout << endl;
        cout << "Weakness: " << weakness << endl;
    }

    string getSecretIdentity() override {
        return realName;
    }
};

int main() {
    // Create a Hero
    Hero hero(
        "Seol Hee", 
        "K-Pop Idol", 
        "Luna Snow", 
        {"Ice Manipulation", "Dark-Ice", "Healing-Ice", "Charm"}, 
        "Fire"
    );

    // Create a Villain
    Villain villain(
        "JARVIS", 
        "Helper to Tony Stark", 
        "Ultron", 
        {"Robot intellect", "Technology integration", "Manipulation"}, 
        "Humanity"
    );

    // Display Hero and Villain details
    hero.print();
    cout << endl;
    villain.print();

    return 0;
}