// Lecture3.cpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Status {
    NORMAL,
    POISONED,
    CONFUSED,
    PARALYZED
};

class Pokemon {
public:
    string name;
    int health;
    Status status = NORMAL;
    void print() {
        string str_status;
        switch (this->status) {
        case NORMAL:
            str_status = "Normal";
            break;
        case POISONED:
            str_status = "Poisoned";
            break;
        case CONFUSED:
            str_status = "Confused";
            break;
        case PARALYZED:
            str_status = "Paralyzed";
            break;
        }
        printf("%s %d %s\n\n", this->name.c_str(), this->health, str_status.c_str());
    }
};

class Item {
public:
    Item(string name) {
        this->name = name;
    }
    string getName() {
        return this->name;
    }
    void use(Pokemon& p) {
        p.health += 100;
    }
private:
    string name;
    int price = 0;
};

struct InventoryItem {
    Item item;
    int qty;
};

class Inventory {
public:
    vector<InventoryItem> items;
    void print() {
        cout << "INVENTORY\n--------------------\n";
        cout << "QTY\tNAME\t\n";
        int total = 0;
        for (InventoryItem ii : this->items) {
            printf("%d\t%s\n", ii.qty, ii.item.getName().c_str());
            total += ii.qty;
        }
        cout << "\nTOTAL: " << total << "\n\n";
    }
};

int main()
{
    // Pokemon
    Pokemon pikachu;
    pikachu.name = "Dave";
    pikachu.health = 50;
    pikachu.print();

    // Items
    Item potion("Potion");
    Item cure("Cure");
    Item pokeball("Pokeball");

    // Items + Amount
    InventoryItem inventory_potion = { potion, 5000 };
    InventoryItem inventory_cure = { cure, 100 };
    InventoryItem inventory_pokeball = { pokeball, 7 };

    // Inventory
    Inventory inventory;
    inventory.items = { inventory_potion, inventory_cure, inventory_pokeball };
    inventory.print();

    // Use all of the items on Dave
    for (InventoryItem& ii : inventory.items) {
        for (int i = ii.qty; i > 0; i--) {
            ii.item.use(pikachu);
            ii.qty--;
        }
    }

    // Display the inventory and pokemon again
    inventory.print();
    pikachu.print();

}