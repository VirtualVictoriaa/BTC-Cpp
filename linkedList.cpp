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
    // Default constructor
    Node* head = NULL;
    Node* tail = NULL;
    Linkedlist()
    {
        this->head = head; // Initialize head to NULL
        this->tail = tail; // Initialize tail to NULL
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
                return nodeOffset; // Return the index if found.
            }
            temp = temp->next;
            nodeOffset++;
            temp = temp->next;
        }
        return -1;
    }

    // insert a node at the end of the list
    void insertNode(int);

    void printList();

    void deleteNode(int);
};

// Function to delete the
// node at given position
void Linkedlist::deleteNode(int nodeOffset)
{
    Node* temp1 = head, * temp2 = NULL;
    int ListLen = 0;

    if (head == NULL) {
        std::cout << "List empty, head empty" << std::endl;
        return;
    }

    while (temp1 != NULL) {         // Find length of the linked-list
        temp1 = temp1->next;
        ListLen++;
    }

    if (ListLen < nodeOffset) {         // Check if the position to be deleted is less than the length
        std::cout << "Index out of range"
            << std::endl;
        return;
    }
    temp1 = head;           // Declare temp1

    // Deleting the head.
    if (nodeOffset == 1) {    // Deleting the head.
        head = head->next;    // Update head
        delete temp1;
        return;
    }

    // Traverse the list to
    // find the node to be deleted.
    while (nodeOffset-- > 0) {
        temp2 = temp1;          // Update temp2
        temp1 = temp1->next;    // Update temp1
    }
    // Change the next pointer
    // of the previous node.
    temp2->next = temp1->next;
    delete temp1;           // Delete the node
}

void Linkedlist::insertNode(int data) // Function to insert a new node.
{
    // Create the new Node.
    Node* newNode = new Node(data);

    if (head == NULL) {             // Assign to head
        this->head = newNode;
        return;
    }
    if (data < head->data) { // Insert at the beginning
        newNode->next = head;      // Update next pointer of new node
        head = newNode;            // Update head
        return;
    }

    Node* temp = head;          // Traverse till end of list
    while (temp->next != NULL) {
        if (data > temp->data && data < temp->next->data) {
            newNode->next = temp->next; // Insert in between
            temp->next = newNode;
            return;
        }
        temp = temp->next;        // Update temp
    }
    temp->next = newNode;       // Insert at the last.
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