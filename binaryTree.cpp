// BinaryTreeHouse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node {
public:
    Node* left = NULL;
    Node* right = NULL;
    int data;
    Node(int data) {
        this->data = data;
    }
};

Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* treecursion(int nums[], int* preIndex, int low, int high, int size) {
    // base cases /////////////////////////////////
    if (*preIndex >= size || low > high) {  
        return NULL;
    }

    // make a new root
    Node* root = newNode(nums[*preIndex]);
    *preIndex += 1;

    // if current subarray has only one element (leaf)
    if (low == high) {
        return root;
    }

    // look for first element greater than root
    int i;
    for (i = low; i <= high; ++i) {
        if (nums[i] > root->data) {
            break;
        }
    }

    // recursive cases /////////////////////
    // use index of that element to divide into 2 parts, left and right
    root->left = treecursion(nums, preIndex, *preIndex, i - 1, size);
    root->right = treecursion(nums, preIndex, i, high, size);

    return root;
}

Node* buildATree(int nums[], int size) {
    int preIndex = 0;
    return treecursion(nums, &preIndex, 0, size - 1, size);
}

// search: search bst for a given key
// @param: Node* root -> root Node of the bst
// @param: int key -> the integer to search for
// returns the Node for the given key if found, NULL otherwise
Node* search(Node* root, int key, bool debug=false) {
    // base case
    if (root == NULL) {
        if (debug)
            cout << "NOT FOUND\n";
        return root;
    }
    if (debug)
        cout << root->data;
    if (key == root->data) {
        return root;
    }
    // recurse
    if (root->data < key) {
        if (debug)
            cout << "->";
        return search(root->right, key, debug);
    }
    if (debug)
        cout << "<-";
    return search(root->left, key, debug);
}

void printInOrder(Node* Node) // LNR
{
    // base case
    if (Node == NULL) {
        return;
    }
    // recursive case
    printInOrder(Node->left); // L
    std::cout << Node->data << " "; // N
    printInOrder(Node->right); // R
}

void printPreOrder(Node* Node) // NLR
{
    // base case
    if (Node == NULL) {
        return;
    }
    // recursive case
    cout << Node->data << " "; // N
    printInOrder(Node->left); // L
    printInOrder(Node->right); // R
}

void printPostOrder(Node* Node) // LRN
{
    // base case
    if (Node == NULL) {
        return;
    }
    // recursive case
    printInOrder(Node->left); // L
    printInOrder(Node->right); // R
    cout << Node->data << " "; // N
}

int main()
{
    int nums[] = {10, 5, 1, 7, 40, 50};   //pre order Node Left Right NLR
    int size = sizeof(nums) / sizeof(nums[0]);

    Node* root = buildATree(nums, size);

    printInOrder(root);  // LNR
    cout << "\n";
    printPreOrder(root);  // NLR
    cout << "\n";
    printPostOrder(root);  // LRN
    cout << "\n";

    Node* found = search(root, 7, true);
    if (found == NULL) {
        cout << "Not FOUND\n";
    }
    else {
        cout << "\n" << found->data << "\n";
    }
}