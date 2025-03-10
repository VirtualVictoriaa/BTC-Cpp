// HelloWorld.cpp
//
// The #include directive tells the compiler where to find
// input(keyboard) and output(screen) information.
// Words with special meaning, like "#include" and "using" and "int" are
// called keywords or reserved words. They usually are given a color
// in an IDE or Integrated Development Environment like VisualStudio.
#include <iostream>
// "using namespace std" tells the compiler to use the standard names
// so you don't have to say std::cout
// new #include statement for string support
#include <string>
using namespace std;
// The start of the program is a function or group of code called 'main'
// It returns an integer so it starts with 'int'
int main()
// Braces identify the start and the end of the function.
{
// To the character-based output (screen) send the text "Hello, World.\n"
cout << "Hello, World.\n";
cout << "This is a C++ program.\n";
// Declare a string variable to store user input
    string userInput;
// Get the input from the user
    getline(cin, userInput);
// Output the input received from the user
    cout << "You entered: " << userInput << endl;
// Ask the Windows operating system to execute the pause command.
// system("pause");
// Exit the program, returning a 0 which means no errors.
// return 0;

// Variables are spaces in memory you reserve with a name and a type.
// Variable names must start with a letter or underscore and may also contain digits.
// All variables in c++ must be declared before used.
// They may be initialized when declared.
// Some code to make doubles have two decimal points
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
// int for integers
int count1;
int count2 = 7;

// double for decimal numbers
double price = 8.00, discount(0.33333), quantity, total;
double cost = 5.50;

// char for letter, use single quotes
char letter, Letter, LETTER;
char letterFromUser;
cin >> letterFromUser;
int diff = 'A' - 'a';
char asciiCode =  letterFromUser - diff;
cout << " ascii code " << int(asciiCode) << " is " << asciiCode << "\n";
//sting for words and phrases in double quotes
string password;
string greeting = "Hi there!";
//Assignment statements
//Stuff on the right goes into the variable on the left
quantity = 5;
total = quantity * price * (1-discount);
//Output together
cout << quantity << " items at " << price << " each with " << 100 * discount << "% discount\n";
//Output in  pieces
cout << "total = ";
cout << total;
cout << endl;
// Rounding test, startt with precision of 2 decimal places
total = .333 + .333 + .333;
cout << "test total = ";
cout << int(total);
cout << endl;
//Change precision to see actual contents
cout.precision(5);
cout << "test total = ";
cout << total;
cout << endl;

int number1, number2;
char letter1, letter2;
string word1, word2;
//simple one question, one answer, into one variable.
cout << "Enter first number: ";
cin >> number1;
cout << "You entered " << number1 << ".\n";
cout << "Enter two numbers separated by a space, then press return: ";
// cin >> number1 >> number2;
cin >> number1
>> number2;
cout << "You entered " << number1 << " and " << number2 << ".\n";
cout << number1 << " + " << number2 << " = " << number1 + number2 << "\n";
cout << "Enter two characters separated by a space, then press return: ";
cin >> letter1 >> letter2;
cout << "You entered " << letter1 << " and " << letter2 << ".\n";
cout << "char + char: " << letter1 << " + " << letter2 << " = " << letter1 + letter2 << "\n";
word1 = letter1 + letter2;
cout << "string = char + char: " << letter1 << " + " << letter2 << " = " << word1 << "\n";
word1 = "";
word1 += letter1;
word1 += letter2;
cout << "string += char: " << letter1 << " + " << letter2 << " = " << word1 << "\n";
cout << "Enter two words separated by a space, then press return: ";
cin >> word1;
cin >> word2;
cout << "You entered " << word1 << " and " << word2 << ".\n";
cout << word1 << " + " << word2 << " = " << word1 + word2 << "\n";

return 0;

//If statements
int number1, number2, number3;
// boolean variables are true or false
bool condition1, condition2;
condition1 = true;
if (condition1)
    cout << "condition1 is true and = " << condition1 << "\n";
else
    cout << "condition1 is false and = " << condition1 << "\n";
// comparison operators result in a true or false condition
cout << "Enter a number: ";
cin >> number1;
cout << "Enter another number: ";
cin >> number2;
if (number1 > number2)
    cout << number1 << " > " << number2 << "\n";
if (number1 < number2)
    cout << number1 << " < " << number2 << "\n";
if (number1 >= number2)
    cout << number1 << " >= " << number2 << "\n";
if (number1 <= number2)
    cout << number1 << " <= " << number2 << "\n";
// Be careful... = assigns, == compares
// if (number1 = number2)
if (number1 == number2)
    cout << number1 << " == " << number2 << "\n";
if (number1 != number2)
    cout << number1 << " != " << number2 << "\n";
// "and" with &&, "or" with ||
if ((number1 >= 1) && (number1 <= 10))
    cout << number1 << " is between 1 and 10\n";
if ((number1 == 5) || (number1 == 7))
    cout << number1 << " is either 5 or 7\n";
// Compound statements (multiple lines in a block)
// use braces to enclose blocks of code.
if (true)
    {
    cout << "One line\n";
    cout << "Another line\n";
    cout << "A third line\n";
    }

    return 0;

// checks the condition and then runs
bool isLoading = true;

std:: cout << "Loading";
while(isLoading) {
    cout << ".";
    isLoading = false;
}
//or
// runs and then checks the condition
do {
    cout << ".";
    isLoading = false;
} while (isLoading);

// Password loop
int tries = 3;
string password = "superstrongpw";
string userPassword;
cout << "Input password: ";
cin >> userPassword;
tries--;

while (password != userPassword && tries > 0) {
    cout << "Invalid login. Try a different one.\n";
    cout << "Input password: ";
    cin >> userPassword;
    tries--;
}
    cout << "Login successful. Welcome back Traveler";

// do-while version
do {
    cout << "Input password: ";
    cin >> userPassword;
    if (password == userPassword) {
        cout << "Login successful. Welcome back Traveler";
        break; //continue;
    }
    tries--;
    cout << "You have " << tries << "tries left.\n";
    } while (tries > 0);
    if (password != userPassword) {
        cout << "Invalid login. Is there another password you'd like to try?\n";
    }
    
// For loop verison
cout << "For Loop version\n";
for (int tries = 2; tries >= 0; tries--) {
    cout << "Input password: ";
    cin >> userPassword;
    if (password == userPassword) {
        cout << "Login successful. Welcome back Traveler";
        break; //continue;
    }
    cout << "Invalid login. Is there another password you'd like to try?\n";
}

return 0;
    int userNum, runningTotal = 1, target = 12;
    cout << "You're target number is " << target << ".\n";

    do {
        cout << "\nInput a numer (2-5) (0 to end): ";
        if (userNum < 2 || userNum > 5) {
            cout << "Not within specified range.\n";
            continue;
        }
        runningTotal = runningTotal * userNum;
    } while (runningTotal != target && userNum != 0);
    
 return 0;

 //Switch Case 
    char input;

    cout << "You have encountered a homophob, what do you do?" << endl << "(A)ttack" << endl << "(D)efend" << endl << "(R)un" << endl;
    cin >> input;
    switch (input) {
        //Cascading, if you don't break, it will continue to the next case
        case 'A':
        case 'a':
            cout << "You attack the homophob. Unfortunately, he spits in your face and you lose vision in your right eye :(" << endl;
            break;
        case 'D':
        case 'd':
            cout << "You defend yourself. Holding up your arms, you block his spit!" << endl;
            break;
        case 'R':
        case 'r':
            cout << "You run away. You're a coward, but at least you're safe." << endl;
            break;
        default:
            cout << "Invalid input. He doesn't seem to mind that you spaced out but you take psychic damage from listening to him." << endl;
            break;
    }
    return 0;

    //Nested Loop. Don't go too deep.
    int trucks=3, pallets=2, cases=16, packs=4, cans=6;
    for (int i = 0; i < trucks; i++) {
        cout << "Truck " << i + 1 << " has " << pallets << " pallets.\n";
        for (int j = 0; j < pallets; j++) {
            cout << "\tPallet " << j + 1 << " has " << cases << " cases.\n";
            for (int k = 0; k < cases; k++) {
                cout << "\t\tCase " << k + 1 << " has " << packs << " packs.\n";
                for (int l = 0; l < packs; l++) {
                    cout << "\t\t\tPack " << l + 1 << " has " << cans << " cans.\n";
                    for int (m = 0; m < cans; m++) {
                        cout << "\t\t\t\tCan " << m + 1 << " is ready to ship.\n";
                    }
                }
            }
        }
    }
    return 0;
    
}

const int ARRAY_LEN = 5;
void printIntArray(int intArray[], int size);
void printCharArray(char charArray[], int size);

int main() {
    //no varible, needs to know how much it can hold before compiling
    //base 0 index
    int numbers[ARRAY_LEN] = {8, 6, 7, 5, 3};
    char characters[ARRAY_LEN] = {'R', 'E', 'S', 'P', 'E'};

    for (int i = 0; i < ARRAY_LEN; i++) {
        cout << numbers[i] << endl;
    }
    cout << "Integers: " << sizeof(int) << " bytes" << endl;
    cout << "Characters: " << sizeof(char) << " bytes" << endl;
    int choice;
    int to_write;
    do {
        printIntArray(numbers, ARRAY_LEN);
        printCharArray(characters, ARRAY_LEN);
         
        cout << "Choose a number between 1 and 5: ";
        cin >> choice;
        cout << "Choose a number to write in: ";
        cin >> to_write;
        /* if (choise < 1 || choice > ARRAY_LEN) {
            cout << "...alright wise guy" << endl;
            continue;
        } */
    } while (choice != 0);
    cout << "You chose: " << numbers[choice - 1] << endl;

    return 0;
}

void printIntArray(int intArray[], int size) {
    for (int i=0; i < size; i++) {
        cout << intArray[i];
    }
    cout << endl;
}

void printCharArray(char charArray[], int size) {
    for (int i=0; i < size; i++) {
        cout << charArray[i];
    }
    cout << endl;
}

const int ARRAY_LEN = 10;

void swap(char& c1, char& c2) {
    char temp = c1;
    c1 = c2;
    c2 = temp;
}
void print(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
    }
    cout << endl;
}
int main() {
    char chars[ARRAY_LEN] = "ShlEo4Nn."
    bool sorted;
    do {
        sorted = true;
        for (int i = 0; i < ARRAY_LEN - 1; i++) {
            cout << chars[i -1] << " : " << chars[i] << endl;
            if (chars[i] > chars[i + 1]) {
                swap(chars[i], chars[i + 1]);
                sorted = false;
            }
        }
    } while (!sorted);
    cout << chars << endl;
}

struct Trainer { //structs are public by default, useless if not
    string name;
    int age;
    string pokemon;
    int badges;
};
struct Pokemon {
    Trainer trainer;
    int id;
    string name;
    string type;
    int level;
    int hp;
    int attack;
    int defense;
    int speed;
};

void printPokemon (Pokemon p) {
    printf("%s\nID #%d\nType %s\n", p.name, p.id, p.type);
    printf("Level %d\nHP %d\nAttack %d\nDefense %d\nSpeed %d\n", p.level, p.hp, p.attack, p.defense, p.speed);
    cout << "Trainer " << p.trainer.name << "\nAge " << p.trainer.age << "\nBadges " << p.trainer.badges << endl;
}

int main() {
    Trainer ash;
    ash.name = "Ash Ketchum";
    ash.age = 10;
    ash.pokemon = "Pikachu";
    ash.badges = 8;

    Pokemon pikachu;
    pikachu.name = "Pikachu";
    pikachu.type = "Electric";
    pikachu.level = 5;
    pikachu.hp = 35;
    pikachu.attack = 55;
    pikachu.defense = 40;
    pikachu.speed = 90;

    cout << ash.name << " is " << ash.age << " years old and has " << ash.badges << " badges." << endl;
    cout << ash.name << " has a " << ash.pokemon << " that is a level " << pikachu.level << " " << pikachu.type << " type." << endl;
    cout << ash.pokemon << " has " << pikachu.hp << " HP, " << pikachu.attack << " attack, " << pikachu.defense << " defense, and " << pikachu.speed << " speed." << endl;
    return 0;
}