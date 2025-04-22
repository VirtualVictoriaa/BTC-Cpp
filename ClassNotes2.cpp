// April 15, 2024

#include <vector>
#include <iostream>
#include <random>
#include <string>

using namespace std;

const int MAX_PRECISSION = 100;

random_device seed;
mt19937 gen{ seed()};
uniform_int_distribution<> dist{0, MAX_PRECISSION};

struct Entanglement {
    Qbit q1, q2;
};

class Qbit {
    public:
        Qbit(){};
        Qbit(double value) {
            this->value = value;
        }
        void randomize() {
            this->value = double(dist(gen))/ MAX_PRECISSION;
            for (int i = 0; i < this->entangled.size(); i++) {
                this->entangled[i].setValue(this->value);
            }
            for (Qbit& qbit: this->entangled) {
                this->entangled[i].setValue(this->value);
            }
        }
        void setValue(double value) {
            this->value = value;
        }
        double getValue() {
            return this->value;
        }
        void entangle(Qbit qbit) {
            this->entangled = qbit;
        }
    private:
        vector<Qbit&> entangled = {};
        double value = 0;
};

class Q {
    public:
        Q(int num_qbits) {
            while(num_qbits > 0) {
                Qbit qbit;
                this->qbits.push_back(qbit);
                num_qbits--;
            }
        };
        vector<Qbit> getQbits() {
            return qbits;
        };
        Qbit& getRandomQbit() {
            this->value = dist(gen) % this->qbits.size
        }
        bool hasValue(double value) { 
            for (Qbit& qbit: this->qbits) {
                if (qbit.getValue() == value) {
                    return true;
                }
            }
            return false;
        }
        void randomize() {
            for (Qbit& qbit: this->qbits) {
                qbit.randomize();
            }
        }
    private:
        vector<Qbit> qbits = {};

};

int main() {
    Q q(100);
    int i = 0;
    for (Qbit& qbit: q.getQbits()) {
        if (!(i % 2)) {
            ;
        }
        i++;
    }
    q.randomize();
    int i = 1;
    cout << "\n\n\tKevin Qburk esq. \n\t|";
    for (Qbit qbit: q.getQbits()) {
        cout << qbit.getValue() << "\t";
        if (i % 10 == 0) {
            cout << "|\n";
        }
        else if (i % 10 == 0) {
            cout << " |\n\t| ";
        }
        i++;
    }
    cout << "\n\n";
    double user_input;
    cout << "Input a search decimal between 0 and 1: ";
    cin >> user_input;
    if (q.hasValue(user_input)) {
        cout << "Your value was found. You have been chosen to carry out the Purge.\n";
    }
    else {
        cout << "No match found. You are safe for now.\n";
    }
};