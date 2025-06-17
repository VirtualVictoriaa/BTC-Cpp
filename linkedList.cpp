// LinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// The linked list stores data in sequential storage, like arrays.Though the data are stored sequentially, the memory locations are not contiguous.
// Unlike an array, the linked list can store data of different data types.

#include <iostream>

// Node class to represent
// a node of the linked list.
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Linked list class to
// implement a linked list.
class Linkedlist {
    Node* head;
    Node* tail;
public:
    Linkedlist() {
        head = nullptr; // Initialize head to nullptr
        tail = nullptr; // Initialize tail to nullptr
    }

    int findNode(int data)
    {
        Node* temp = head;
        if (head == NULL) {
            return -1;
        }
        int nodeOffset = 0;
        // Traverse the list to find the node.
        while (temp != NULL) {
            if (temp->data == data) {
                return nodeOffset;
            }
            temp = temp->next;
            nodeOffset++;
        }
        return -1;
    }

    // insert a node at the end of the list
    void insertNode(int);

    void printList();

    void printListReverse();

    void deleteNode(int);
};

// Function to delete the
// node at given position
void Linkedlist::deleteNode(int nodeOffset) {
    if (head == nullptr) return;
    Node* temp = head;
    int ListLen = 0;
    while (temp && ListLen < nodeOffset) {
        temp = temp->next;
        ListLen++;
    }
    if (!temp) return; // Out of range

    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next; // Deleting head

    if (temp->next) temp->next->prev = temp->prev;
    else tail = temp->prev; // Deleting tail

    delete temp;
}

void Linkedlist::insertNode(int data) // Function to insert a new node.
{
    // Create the new Node.
    Node* newNode = new Node(data);

    if (head == NULL) {             // Assign to head
        head = tail = newNode;     // If list is empty, assign head and tail to new node?
        return;
    }
    if (data < head->data) { // Insert at the beginning
        newNode->next = head;      // Update next pointer of new node
        head->prev = newNode;      // Update previous pointer of head
        head = newNode;            // Update head
        return;
    }

    Node* temp = head;          // Traverse till end of list
    while (temp->next != NULL) {
        if (data > temp->data && data < temp->next->data) {
            newNode->next = temp->next; // Insert in between
            newNode->prev = temp;       // Update previous pointer of new node
            temp->next->prev = newNode; // Update previous pointer of next node
            temp->next = newNode;
            return;
        }
        temp = temp->next;        // Update temp
    }
    temp->next = newNode;       // Insert at the last.
    newNode->prev = temp;       // Update previous pointer of new node
    tail = newNode;             // Update tail to the new node
}

// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
    Node* temp = head;

    // Check for empty list.
    if (head == NULL) {
        std::cout << "List empty, head empty" << std::endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

void Linkedlist::printListReverse() {
    Node* temp = tail;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
    std::cout << std::endl;
}

int main()
{
    Linkedlist list;
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(70);
    list.insertNode(93);
    list.insertNode(10);
    list.insertNode(64);
    list.insertNode(15);
    list.insertNode(42);
    std::cout << "Elements of the list are: ";
    list.printList();
    std::cout << std::endl;
    list.deleteNode(2);
    std::cout << "Elements of the list are: ";
    list.printList();
    std::cout << std::endl;
    std::cout << "Input a number to search for: ";
    int search;
    std::cin >> search;
    if (list.findNode(search) != -1) {
        std::cout << "Found " << search << " at index: " << list.findNode(search) << std::endl;
    } else {
        std::cout << search << " not found in the list." << std::endl;
    }
    return 0;
}