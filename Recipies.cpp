#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Food {
public:
    Food(string name, int calories, vector<string> flavors);
    int calorieCount();
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

// Get calorie count
int Food::calorieCount() {
    return calories;
}

// Check flavor of food
bool Food::hasFlavor(string flavor) {
    for (string f : flavors) {
        if (f == flavor) {
            return true;
        }
    }
    return false;
}

// Recipe class definition
class Recipe {
public:
    Recipe(string name, int servings);
    void addFood(Food food, int amount);
    int servingCalories();
    void display();

private:
    string name;
    int servings;
    vector<pair<Food, int>> ingredients; // Pair of Food and its amount
};

// Constructor
Recipe::Recipe(string name, int servings) {
    this->name = name;
    this->servings = servings;
}

// Add however much food to the recipe
void Recipe::addFood(Food food, int amount) {
    ingredients.push_back(make_pair(food, amount));
}

// Calculate total calories per serving
int Recipe::servingCalories() {
    int totalCalories = 0;
    for (auto& ingredient : ingredients) {
        totalCalories += ingredient.first.calorieCount() * ingredient.second;
    }
    return totalCalories / servings;
}

// Display the secret recipe :O
void Recipe::display() {
    cout << "Recipe: " << name << endl;
    cout << "Servings: " << servings << endl;
    cout << "Ingredients:" << endl;
    for (auto& ingredient : ingredients) {
        cout << "- " << ingredient.second << " " << ingredient.first.name 
             << " (" << ingredient.first.calorieCount() << " calories each)" << endl;
    }
    cout << "Calories per serving: " << servingCalories() << endl;
}

int main() {
    cout << "This is the secret recipe for Marshall 'Eminem' Bruce Mathers III and his claim to fame" << endl;
    cout << "Even though he made a diss track about her..." << endl;
    cout << "And she made a diss track about him..." << endl;
    cout << "But they made up so it's okay!" << endl;
    cout << "--------------------Mom's Spaghetti--------------------" << endl;
    // Create Food items
    Food spaghetti("Spaghetti Noodles", 360, {"starchy"});
    Food tomato("Tomato", 80, {"juicy", "tart"});
    Food basil("Basil", 10, {"herbal", "aromatic"});
    Food onion("Yellow Onion", 120, {"savory", "aromatic"});
    Food garlic("Garlic Clove", 20, {"pungent", "aromatic"});

    // Create a Recipe
    Recipe momsSpaghetti("Mom's Spaghetti", 6);

    // Add ingredients to the recipe
    momsSpaghetti.addFood(spaghetti, 1); // 1 package
    momsSpaghetti.addFood(tomato, 3);   // 3 whole tomatoes
    momsSpaghetti.addFood(basil, 2);    // 2 sprigs of basil
    momsSpaghetti.addFood(onion, 1);    // 1 chopped onion
    momsSpaghetti.addFood(garlic, 1);   // 1 minced garlic clove

    // Display the recipe
    momsSpaghetti.display();

    return 0;
}