/* Q. A Dictionary using BST: A Dictionary stores key and value pairs
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be
comparable, Keys must be unique.
Standard Operations: Insert(key, value), Find(key), Delete(key)
Write a menu driven C++ program to provide above standard operations
on dictionaries and provide a facility to display whole data sorted in
ascending/ Descending order. Also find how many maximum
comparisons may require for finding any keyword.
Use Binary Search Tree for implementation */

#include <bits/stdc++.h>
using namespace std;

// node of a BST
struct node
{
    int key;
    string value;
    node *left;
    node *right;
};

// function to create a node
node *createNode(int key, string value)
{
    node *newNode = new node;
    newNode->key = key;
    newNode->value = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// funtion to insert a node
node *insertNode(node *root, int key, string value)
{
    if (root == nullptr)
        return createNode(key, value);
    if (key > root->key)
        root->right = insertNode(root->right, key, value);
    else
        root->left = insertNode(root->left, key, value);
    return root;
}

// function to search a node
int search(node *root, int key, int counter)
{
    if (root == nullptr)
        return -1;
    if (root->key == key)
    {
        cout << "Key found successfully.\nValue: " << root->value << endl;
        return ++counter;
    }
    if (key < root->key)
        return search(root->left, key, ++counter);
    if (key > root->key)
        return search(root->right, key, ++counter);
}

// function to find minimum value key in the BST
node *minValue(node *root)
{
    node *temp = root;
    while (temp && temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}

// function to delete a node
node *deleteNode(node *root, int key)
{
    if (root == nullptr)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == nullptr)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == nullptr)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *minValueNode = minValue(root->right);
        root->key = minValueNode->key;
        root->value = minValueNode->value;
        root->right = deleteNode(root->right, minValueNode->key);
    }
    return root;
}

// to print keys in asscending order
void ascendingOder(node *root)
{
    if (root != nullptr)
    {
        ascendingOder(root->left);
        cout << root->key << " ";
        ascendingOder(root->right);
    }
}

// to print keys in decending order
void decendingOrder(node *root)
{
    if (root != nullptr)
    {
        decendingOrder(root->right);
        cout << root->key << " ";
        decendingOrder(root->left);
    }
}

// main function
int main()
{
    // empty bst
    node *root = nullptr;
    int choice, key, result;
    string value;
    do
    {
        cout << "Menu" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Find" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Print in ascending order" << endl;
        cout << "5. Print in decending order" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Key: ";
            cin >> key;
            cout << "Value: ";
            cin >> value;
            root = insertNode(root, key, value);
            cout << "Node inserted successfully." << endl;
            break;
        case 2:
            cout << "Key: ";
            cin >> key;
            result = search(root, key, 0);
            if (result == -1)
            {
                cout << key << " not found." << endl;
            }
            else
            {
                cout << "found in " << result << " steps.\n";
            }
            break;
        case 3:
            cout << "Key: ";
            cin >> key;
            root = deleteNode(root, key);
            cout << "Key deleted successfully.\n";
            break;
        case 4:
            cout << "Ascending order: ";
            ascendingOder(root);
            cout << endl;
            break;
        case 5:
            cout << "Decending order: ";
            decendingOrder(root);
            cout << endl;
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (choice != 6);
}