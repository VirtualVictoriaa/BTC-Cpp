// June 26, 2025 Final for C++ Class
/*
// Why isn't this code working and how might we fix it?

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


// Uh oh, this code is blowing up!
// Add a try-catch block to handle the exception and print the error message.

#include <iostream>
#include <stdio.h>
#include <exception>

struct OopsException : public std::exception
{
    const char* what() const throw ()
    {
        return "Uh oh, spaghetti codes.\n";
    }
};

int runTheNumbers(int x, int y) {
    if (y == 0)
        throw OopsException();
    else
        return (x+y)*x / y;
}

int main()
{
    int x = 5, y = 0;

    try {
        printf("runTheNumbers(%d, %d) = %d\n", x, y, runTheNumbers(x, y));
    } catch (const OopsException& e) {
        std::cerr << "Caught a wild exception!: " << e.what();
    }
    catch (const std::exception& e) {
        std::cerr << "Caught a general exception!: " << e.what();
    }

    return 0;
}


// Given the following code, explain the purpose of the while loop
// and it's contents in insertionSort

#include <iostream>

void insertionSort(int arr[], int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        // explain what the while loop below is doing
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << '\n';
}

int main()
{
    int numbers[] = { 9, 0, 5, 3, 8, 1, 4, 6, 7, 10, 2 };
    int size = sizeof(numbers) / sizeof(numbers[0]);
    insertionSort(numbers, size);
    print(numbers, size);
}

// What is going on with this code and why won't it stop?
#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;
    printList(head);
}


// Given the following code,
// what is the next animal from the queue, AND the next plant from the stack?

#include <iostream>
#include <queue>
#include <stack>

int main() {
    std::queue<std::string> animals;
    animals.push("Aardvark");
    animals.push("Bobcat");
    animals.push("Cougar");
    animals.pop();

    std::stack<std::string> plants;
    plants.push("Acacia");
    plants.pop();
    plants.push("Balsa");
    plants.push("Cedar");
}
*/

// Given the following templated functions f(),
// which cout is called given f('a', 10);

#include<iostream>
#include <type_traits>
using namespace std;

template<typename T1, typename T2>
void f(T1 x, T2 y)
{
    if (is_same<T1, string>::value) {        
        for (int i = y; i > 0; i--) {
            cout << x << "1"; // Option #1
        }
    }
    else {        
        for (int i = y; i > 0; i--) {
            cout << x << "2"; // Option #2
        }
    }
    
}

template<>
void f<char, int>(char x, int y)
{    
    for (int i = y; i > 0; i--) {
        cout << x << "3"; // Option #3
    }
}

template<>
void f<int, int>(int x, int y)
{
    for (int i = y; i > 0; i--) {
        cout << x << "4"; // Option #4
    }
}

int main()
{
    f('a', 10);
}