/* Q. Expression tree: Write a menu driven C++ program to construct an
expression tree from the given prefix expression eg. +--a*bc/def and
perform following operations:
1. Traverse it using post order traversal (non recursive)
2. Delete the entire tree
3. Change a tree so that the roles of the left and right pointers are
swapped at every node. */

#include <bits/stdc++.h>
using namespace std;


// node of expression tree 
struct node {
    char ch;
    node* left;
    node* right;
};

// function to create a node
node* createNode(char ch) {
    node* newNode = new node;
    newNode->ch = ch;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// function to construct expression tree from prefix expression 
node* constructExpressionTree (string prefix) {
    stack <node*> st;
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isalnum(ch)) {
            node* newNode = createNode(ch);
            st.push(newNode);
        } 
        else {
            node* newNode = createNode(ch);
            newNode->left = st.top();
            st.pop();
            newNode->right = st.top();
            st.pop();
            st.push(newNode);
        }
    }
    return st.top();
}

// postorder traversal without recursion
void postorder(node* root) {
    stack <node*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
        node* current = st1.top();
        st1.pop();
        st2.push(current);
        if (current->left)
            st1.push(current->left);
        if (current->right)
            st1.push(current->right);
    }
    while (!st2.empty()) {
        node* temp = st2.top();
        st2.pop();
        cout << temp->ch << " ";
    }
    cout << endl;
}

// delete the entire tree 
void deleteTree(node* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// swap the left and right pointers
void swapPtr(node* root) {
    if (root == nullptr) {
        return;
    }

    swapPtr(root->left);
    swapPtr(root->right);
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// main method
int main () {
    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;
    node* root = constructExpressionTree(prefix);
    int choice;
    do
    {
        cout << "Menu\n";
        cout << "1. Traverse it using post order traversal (non recursive)" << endl;
        cout << "2. Delete the entire tree." << endl;
        cout << "3. Swap left and right pointers. " << endl;
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                postorder(root);
                break;
            case 2:
                deleteTree(root);
                cout << "Tree deleted successfully." << endl;
                break;
            case 3:
                swapPtr(root);
                cout << "Pointers swapped successfully.\n";
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid input\n";
        }
    } while (choice != 4);
}