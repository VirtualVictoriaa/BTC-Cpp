#include <iostream>
using namespace std;

int main() {
char input;

do {
    cout << "You have encountered a homophob, what do you do?" << endl << "(A)ttack" << endl << "(D)efend" << endl << "(R)un" << endl << "(Q)uit" << endl;
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
}
while (input != 'Q' && input != 'q');
return 0;
}