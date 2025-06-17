#include <iostream>
#include <vector>
#include <type_traits>

using namespace std;

struct NissanGTR {
    float psi_boost;
    bool operator >(NissanGTR const& gtr) {
        return this;
    }
    friend ostream& operator<<(ostream& os, const NissanGTR& gtr) {
        os << "Nissan GTR with boost: " << gtr.psi_boost << " psi";
        return os;
    }
};

template<typename T>
void printArray(T arr[], int n) {
    if (is_same<T, int>::value) {
        cout << "LOOK! An INT!";
    }
    else if (is_same<T, char>::value) {
        cout << "LOOK! A CHAR!";
    
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<>
void printArray(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ". ";
    }
    cout << endl;
}

template<typename T>
void sort(T arr[], int n){
    for (int i = 0; i < n -1; i++){
        for (int j = 0; j < n - i -1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int int_arr[] = {75, 88, 199, 200, 65};
    sort (int_arr, sizeof(int_arr) / sizeof(int));
    printArray(int_arr, sizeof(int_arr) / sizeof(int));
    char char_arr[] = {75, 88, 90, 71, 65};
    sort (char_arr, sizeof(char_arr) / sizeof(char));
    printArray(char_arr, sizeof(char_arr) / sizeof(char));
    NissanGTR gtr_arr[] = { {20.5}, {25.0}, {15.0} };
    sort(gtr_arr, sizeof(gtr_arr) / sizeof(NissanGTR));
    printArray(gtr_arr, sizeof(gtr_arr) / sizeof(NissanGTR));
}