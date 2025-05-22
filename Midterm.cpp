// Given the following Music class, construct it in main and invoke it's print function
/*
#include <iostream>

class Music {
public:
    Music(std::string track) {
        this->track = track;
    }
    void play() {
        std::cout << this->track << "\n";
    }
    std::string track;
};

int main()
{
    // construct the class and call print here...
    Music myMusic("Big Iron by Marty Robbins");
    myMusic.play();
}

// Given the following vector of Pokemon, print out each of their names.

#include <iostream>
#include <vector>

struct Pokemon {
    std::string name;
    std::vector<std::string> weaknesses;
};

int main()
{
    std::vector<Pokemon> myPokemon =
    {
        {"Pikachu", {"ground"}},
        {"Charizard", {"water", "wind"}},
        {"Gengar", {"light"}}
    };
    // print the names here...
    for (const auto& pokemon : myPokemon) {
        std::cout << pokemon.name << std::endl;
    }
}

// Given the same vector of Pokemon, print out each of their weaknesses.

#include <iostream>
#include <vector>

struct Pokemon {
    std::string name;
    std::vector<std::string> weaknesses;
};

int main()
{
    std::vector<Pokemon> myPokemon =
    {
        {"Pikachu", {"ground"}},
        {"Charizard", {"water", "wind"}},
        {"Gengar", {"light"}}
    };
    // print the weaknesses here...
    for (const auto& pokemon : myPokemon) {
        std::cout << pokemon.name << " Weaknesses: ";
        for (const auto& weakness : pokemon.weaknesses) {
            std::cout << weakness << " ";
        }
        std::cout << std::endl;
    }

}

class Obfuscated {
    double x;
    int y;
    float z;
public:
    double a() {
        return 0.0;
    }
    double b() {
        return x;
    }
    void c(int y) {
        this->y = y;
    }
    float d() {
        return z;
    }
    void e(double x) {}
};

int main()
{
    return 0;
}

// Give this class a default constructor and call the build function in main.

#include <stdio.h>

class Skyscraper {
public:
    // create default constructor here
    Skyscraper() : floors(3), sqft(9999) {}

    void build() {
        printf("Building a %0.2f sqft, %d floor skyscraper!\n", 
            this->sqft, this->floors);
    }
private:
    int floors;
    double sqft;
};

int main()
{
    // construct the class and call build here
    Skyscraper mySkyscraper;
    mySkyscraper.build();
}

// Why isn't this code working and how might we fix it?
// It should print "Hooray, it's working" once the error is fixed.

#include <iostream>

class MyPerfectClass {
public:
    MyPerfectClass() {
        this->favoriteNumber = 5;
    }
    void pleaseWork() {
        std::cout << "Hooray, it's working!";
    }
private:
    int favoriteNumber;
};

int main()
{
    MyPerfectClass mpc;
    mpc.pleaseWork();
}

// Why isn't this code working and how can we fix it?
// Note the namespace being used.

namespace foo
{
    namespace bar
    {
        struct Log { };
    }
}

using namespace foo;

int main()
{
    bar::Log l = {};
}

// Overload the plus(+) operator such that two points added together create a new point with the coordinates added together.

#include <stdio.h>

class Point {
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    };
    void print() {
        printf("(%d, %d)\n", this->x, this->y);
    }
    // overload the + operator here
    Point operator+(const Point& other) {
        return Point(this->x + other.x, this->y + other.y);
    }
private:
    int x;
    int y;
};

int main()
{
    Point point1(7, 10);
    Point point2(3, -13);

    Point point3 = point1 + point2;
    point3.print(); // should print (10, -3)
}
*/
