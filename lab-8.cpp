/* Q. A Dictionary using AVL: A Dictionary stores key and value pairs
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be
comparable, Keys must be unique.
Standard Operations: Insert(key, value), Find(key), Delete(key)
Write a menu driven C++ program to provide above standard operations
on dictionaries and provide a facility to display whole data sorted in
ascending/ Descending order. Also find how many maximum
comparisons may require for finding any keyword.
Use Height balanced tree(AVL) and find the complexity for finding a
keyword. */

#include <bits/stdc++.h>
using namespace std;

// stucture of node
struct node
{
    int key;
    string value;
    node *left;
    node *right;
    int height;
    // constructor
    node(int k, string v)
    {
        key = k;
        value = v;
        height = 1;
        left = right = nullptr;
    }
};

// func to create a new node
node *createNode(int key, string value)
{
    node *newNode = new node(key, value);
    return newNode;
}

// func to get height
int getHeight(node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

// func to get max of 2 numbers
int getMax(int a, int b)
{
    return (a > b) ? a : b;
}

// function to get balancing factor
int balancingFactor(node *root)
{
    if (root == NULL)
        return 0;

    return (getHeight(root->left) - getHeight(root->right));
}

// function to rotate right
node *rotateRight(node *root)
{
    node *temp1 = root->left;
    node *temp2 = temp1->right;

    temp1->right = root;
    root->left = temp2;

    root->height = 1 + getMax((getHeight(root->left)), (getHeight(root->right)));
    temp1->height = 1 + getMax((getHeight(temp1->left)), (getHeight(temp1->right)));

    return temp1;
}

// function to rotate left
node *rotateLeft(node *root)
{
    node *temp1 = root->right;
    node *temp2 = temp1->left;

    temp1->left = root;
    root->right = temp2;

    root->height = 1 + getMax((getHeight(root->left)), (getHeight(root->right)));
    temp1->height = 1 + getMax((getHeight(temp1->left)), (getHeight(temp1->right)));

    return temp1;
}

// function to insert a node
node *insertNode(node *root, int key, string value)
{
    if (root == nullptr)
        return createNode(key, value);

    if (key > root->key)
        root->right = insertNode(root->right, key, value);

    else if (key < root->key)
        root->left = insertNode(root->left, key, value);

    else
        root->value = value;

    root->height = 1 + getMax((getHeight(root->left)), getHeight(root->right));
    int balance = balancingFactor(root);

    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    if (balance > 1 && key > root->left->key)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);

    if (balance < -1 && key < root->right->key)
    {
        root->right = rotateRight(root->right);
        return rotateRight(root);
    }

    return root;
}

// func to find a key
node *find(node *root, int key, int &counter)
{
    if (root == nullptr)
        return nullptr;

    counter++;

    if (key > root->key)
        return find(root->right, key, counter);

    if (key < root->key)
        return find(root->left, key, counter);

    if (key == root->key)
        return root;
}

// func to find min value node
node *minValueNode(node *root)
{
    node *temp = root;
    while (temp && temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}

// function to delete the node
node *deleteNode(node *root, int key)
{
    if (root == nullptr)
        return nullptr;

    if (key > root->key)
        root->right = deleteNode(root->right, key);

    else if (key < root->key)
        root->left = deleteNode(root->left, key);

    else
    {
        if (root->left == nullptr)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == nullptr)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        node *inorderSuccessor = minValueNode(root->right);
        root->key = inorderSuccessor->key;
        root->value = inorderSuccessor->value;

        root->right = deleteNode(root->right, inorderSuccessor->key);
    }

    if (root == nullptr)
        return root;

    root->height = 1 + getMax(getHeight(root->left), getHeight(root->right));

    int balance = balancingFactor(root);

    if (balance > 1 && balancingFactor(root->left) >= 0)
    {
        return rotateRight(root);
    }

    if (balance > 1 && balancingFactor(root->left) < 0)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && balancingFactor(root->right) <= 0)
    {
        return rotateLeft(root);
    }

    if (balance < -1 && balancingFactor(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// print in ascending order
void AO(node *root)
{
    if (root != nullptr)
    {
        AO(root->left);
        cout << root->key << " ";
        AO(root->right);
    }
}

// print in descending order
void DO(node *root)
{
    if (root != nullptr)
    {
        DO(root->right);
        cout << root->key << " ";
        DO(root->left);
    }
}

// main function
int main()
{
    node *root = nullptr;
    node *temp = nullptr;
    int choice, key, counter;
    string value;
    int result;
    do
    {
        cout << "Menu\n1. Insert\n2. Delete\n3. Find\n4. Print ascending order\n5. Print descending order\n6. Exit\n";
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
            cout << "Node inserted successfully\n";
            break;

        case 2:
            cout << "Key: ";
            cin >> key;
            root = deleteNode(root, key);
            cout << "Node deleted successfully\n";
            break;

        case 3:
            cout << "Key: ";
            cin >> key;
            counter = 0;
            temp = find(root, key, counter);
            if (temp == nullptr)
            {
                cout << "Key not found\n";
            }
            else
            {
                cout << "Key found\n";
                cout << "Value: " << temp->value << "\n";
                cout << "Number of comparisons: " << counter << "\n";
            }
            break;

        case 4:
            cout << "Printing in ascending order:\n";
            AO(root);
            cout << endl;
            break;

        case 5:
            cout << "Printing in descending order:\n";
            DO(root);
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