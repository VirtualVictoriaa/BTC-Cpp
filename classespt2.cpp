#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Food {
public:
    Food(string name, int calories, vector<string> flavors);
    int getCalorieCount();
    bool hasFlavor(string flavor);
    string name;
private:
    int calories;
    vector<string> flavors;
};

// Constructor
Food::Food(string name, int calories, vector<string> flavors) {
    this->name = name;
    this->calories = calories;
    this->flavors = flavors;
}

// getCalorieCount goes here
int Food::getCalorieCount() {
    return calories;
}

// hasFlavor goes here
bool Food::hasFlavor(string flavor) {
    for (string f : flavors) {
        if (f == flavor) {
            return true;
        }
    }
    return false;
}

int main() {
    // Create 4 Food items
    Food apple("Apple", 95, {"sweet", "tart"});
    Food pizza("Pizza", 285, {"savory", "cheesy", "tomato"});
    Food iceCream("Ice Cream", 137, {"sweet", "creamy", "vanilla"});
    Food curry("Curry", 350, {"spicy", "savory", "aromatic"});

    // Add them to a vector
    vector<Food> foods = {apple, pizza, iceCream, curry};

    string userFlavor;
    while (true) {
        cout << "Enter a flavor to search (or 'quit' to exit): ";
        getline(cin, userFlavor);

        if (userFlavor == "quit") {
            break;
        }

        // Check each food for the flavor
        for (Food food : foods) {
            if (food.hasFlavor(userFlavor)) {
                cout << food.name << " has this flavor (" 
                     << food.getCalorieCount() << " calories)" << endl;
            }
        }
    }

    return 0;
}