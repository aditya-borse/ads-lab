/* Q. A Dictionary using Hash table:
    A Dictionary stores key and value pairs
    Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be
    comparable, Keys must be unique.
    Standard Operations: Insert(key, value), Find(key), Delete(key)
    Write a menu driven C++ program to provide above standard operations
    on dictionaries
    Write a menu driven C++ program to provide all the functions of a
    dictionary (ADT) using hashing and handle collisions using chaining.
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    string value;
    node *next;
    node(int k, string s)
    {
        key = k;
        value = s;
        next = nullptr;
    }
};

const int SIZE = 10;

node *createNode(int key, string value)
{
    node *newNode = new node(key, value);
    return newNode;
}

int hashFunction(int key)
{
    return key % SIZE;
}

void insertKeyValue(vector<node *> &dict, int key, string value)
{
    int index = hashFunction(key);

    if (dict[index] == nullptr)
        dict[index] = createNode(key, value);

    else
    {
        node *temp = dict[index];
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = createNode(key, value);
    }
    cout << "Inserted successfully\n";
}

node* search(vector<node*> &dict, int key) 
{
    int index = hashFunction(key);
    if (dict[index] == nullptr)
        return nullptr;

    else
    {
        node* temp = dict[index];
        while(temp != nullptr) 
        {   
            if (temp->key == key) 
            {
                return temp;
            }
            temp = temp->next;
        }
    }    
    return nullptr;                                                                                                                                                                                                                
}

void deleteKeyValue(vector <node*> &dict, int key)
{
    int index = hashFunction(key);
    if (dict[index] == nullptr)
    {
        cout << "Key does not exist\n";
        return;
    }

    else 
    {
        node* temp = dict[index];
        if (temp->key == key)
        {
            dict[index] = dict[index]->next;
            delete temp;
            cout << "Deleted successfully\n";
            return;
        }

        node* pre = dict[index];
        node* curr = dict[index]->next;
        while(curr != nullptr)
        {
            pre->next = curr->next;
            if (curr->key == key) {
                delete curr;
                cout << "Deleted successfully\n";
                return;
            }
        }
        cout << "Key not found\n";
        return;
    }
}

int main() 
{
    vector <node*> dict(SIZE, nullptr);
    int key, choice;
    string value;
    node* temp;
    do
    {
        cout << "\n\n\t\t\t Menu\n\n";
        cout << "\t\t\t1. Insert\n\n";
        cout << "\t\t\t2. Delete\n\n";
        cout << "\t\t\t3. Search\n\n";
        cout << "\t\t\t4. Exit\n\n";
        cout << "\t\t\tEnter choice: ";
        cin >> choice;
        cout << "\n\n--------------------------------------------------------------------------------\n\n";
        switch(choice)
        {
            case 1:
                cout << "Key: ";
                cin >> key;
                cin.ignore();
                cout << "Value: ";
                getline(cin, value);
                insertKeyValue(dict, key, value);
                break;

            case 2:
                cout << "Key: ";
                cin >> key;
                deleteKeyValue(dict, key);
                break;

            case 3:
                cout << "Key: ";
                cin >> key;
                temp = search(dict, key);
                if (temp)
                {
                    cout << "Found\n";
                    cout << "Value: " << temp->value << endl;
                }
                else 
                {
                    cout << "Not found\n";
                }
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);   
}