#ifndef FOOD_H
#define FOOD_H

#include <string>
#include <vector>

namespace food {

class Food {
public:
    Food(std::string name, int calories, std::vector<std::string> flavors);
    int calorieCount();
    bool hasFlavor(std::string flavor);
    std::string name;

    // Operator overload
    Food operator+(const Food& other) const;

private:
    int calories;
    std::vector<std::string> flavors;
};

} // namespace food

#endif