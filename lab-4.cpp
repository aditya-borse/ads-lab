/* Q. Binary search tree: Write a menu driven C++ program to construct a
binary search tree by inserting the values in the order given, considering at
the beginning with an empty binary search tree, After constructing a
binary tree. Insert new node, ii. Find number of nodes in longest path from root, iii.
Minimum data value found in the tree iv. Search a value v. Print values
in ascending and descending order */

#include <bits/stdc++.h>
using namespace std;

// node of BST
struct node
{
    int data;
    node *left;
    node *right;
};

// create a new node
node *createNode(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->left = newnode->right = nullptr;
    return newnode;
}

// insert a new node
node *insertNode(node *root, int data)
{
    if (root == nullptr)
        return createNode(data);

    if (data > root->data)
        root->right = insertNode(root->right, data);

    else
        root->left = insertNode(root->left, data);

    return root;
}

// find height of tree
int height(node *root)
{
    if (root == nullptr)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// find minimum value
int findMinimumValue(node *root)
{
    if (root != NULL)
    {
        node *current = root;
        while (current && current->left != nullptr)
            current = current->left;

        return current->data;
    }
    return -1;
}

// search a value
int search(node *root, int key, int count)
{
    if (root == nullptr)
        return -1;
    if (root->data == key)
        return ++count;
    if (key < root->data)
        return search(root->left, key, ++count);
    if (key > root->data)
        return search(root->right, key, ++count);
}

// printing elements in asscending order
void asscending(node *root)
{
    if (root != nullptr)
    {
        asscending(root->left);
        cout << root->data << " ";
        asscending(root->right);
    }
}

// printing elements in descending order
void descending(node *root)
{
    if (root != nullptr)
    {
        descending(root->right);
        cout << root->data << " ";
        descending(root->left);
    }
}

// main function
int main()
{
    // creating an empty BST
    node *root = nullptr;

    int N;
    cout << "Number of node: ";
    cin >> N;

    cout << "Enter the data to be inserted: ";
    int data;
    for (int i = 0; i < N; i++)
    {
        cin >> data;
        root = insertNode(root, data);
    }

    int choice, key, result;
    do
    {
        cout << "Menu\n1. Insert a new node.\n2. Find height of the tree\n3. Find minimum data value\n4. Search for a value\n5. Print values in ascending order\n6. Print values in descending order\n7. Exit\nEnter Choice: ";

        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Value: ";
            cin >> data;
            root = insertNode(root, data);
            cout << "Data inserted successfully.\n";
            break;
        case 2:
            cout << "Height: " << height(root);
            cout << endl;
            break;
        case 3:
            result = findMinimumValue(root);
            if (result == -1) {
                cout << "Tree is empty.";
                cout << endl;
            }
            else {
                cout << "Minimum value: " << result << endl;
            }
            break;
        case 4:
            cout << "Key: ";
            cin >> key;
            result = search(root, key, 0);
            if (result == -1) {
                cout << "Key not found.\n";
            }
            else {
                cout << "Key found in " << result << " steps.\n";
            }
            break;
        case 5:
            cout << "Ascending: ";
            asscending(root);
            cout << endl;
            break;
        case 6:
            cout << "Descending: ";
            descending(root);
            cout << endl;
            break;
        case 7:
            cout << "Terminating... :)\n";
            break;
        default: 
            cout << "Invalid input\n";
        }
    } while (choice != 7);
}