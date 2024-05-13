/*
Q. Write a C++ program to construct the binary tree with a given preorder and
   inorder sequence and print the preorder, inorder and post order traversal
   of the constructed tree.
*/

#include <bits/stdc++.h>
using namespace std;

// node of binary tree
struct node
{
    int key;
    node *left;
    node *right;

    // constructor
    node(int val)
    {
        key = val;
        left = right = nullptr;
    }
};

// function to find index of a key from inorder traversal
int findIndex(vector<int> &inorder, int inStart, int inEnd, int key)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inorder[i] == key)
            return i;
    }
    return -1;
}

// function to build the binary tree from inorder and preorder
node *buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd)
{
    if (preStart > preEnd || inStart > inEnd)
        return nullptr;

    int rootValue = preorder[preStart];
    node *root = new node(rootValue);

    int rootIndex = findIndex(inorder, inStart, inEnd, rootValue);
    int leftSize = rootIndex - inStart;

    root->left = buildTree(preorder, preStart + 1, preStart + leftSize, inorder, inStart, rootIndex - 1);
    root->right = buildTree(preorder, preStart + leftSize + 1, preEnd, inorder, rootIndex + 1, inEnd);

    return root;
}

// preorder traversal
void preorderTraversal(node *root)
{
    if (root == nullptr)
        return;

    cout << root->key << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// inorder traversal
void inorderTraversal(node *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

// post order traversal
void postorderTraversal(node *root)
{
    if (root == nullptr)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->key << " ";
}

// main function
int main()
{
    vector <int> preorder;
    vector <int> inorder;

    string preSq, inSq;

    cout << "Enter pre order squence: ";
    cin >> preSq;

    cout << "Enter in order squence: ";
    cin >> inSq;

    for (int i = 0; i < preSq.length(); i++) 
    {
        preorder.push_back(static_cast<int>(preSq[i]) - '0');
    }

    for (int i = 0; i < inSq.length(); i++) 
    {
        inorder.push_back(static_cast<int>(inSq[i]) - '0');
    }

    node* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Post order traversal: ";
    postorderTraversal(root);
    cout << endl;
}