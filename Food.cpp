#include "Food.h"

namespace food {

Food::Food(std::string name, int calories, std::vector<std::string> flavors) {
    this->name = name;
    this->calories = calories;
    this->flavors = flavors;
}

int Food::calorieCount() {
    return this->calories;
}

bool Food::hasFlavor(std::string flavor) {
    for (std::string f : this->flavors) {
        if (f == flavor) {
            return true;
        }
    }
    return false;
}

Food Food::operator+(const Food& other) const {
    std::string combinedName = this->name + " and " + other.name;
    int combinedCalories = this->calories + other.calories;
    std::vector<std::string> combinedFlavors = this->flavors;
    combinedFlavors.insert(combinedFlavors.end(), other.flavors.begin(), other.flavors.end());
    return Food(combinedName, combinedCalories, combinedFlavors);
}

} // namespace food