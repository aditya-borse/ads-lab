/* Q. Flight management: There are flight paths between cities. If there is a
flight between city A and city B then there is an edge between the cities.
The cost of the edge can be the time that flight takes to reach city B from
A, or the amount of fuel used for the journey.
Write a menu driven C++ program to represent this as a graph using
adjacency matrix and adjacency list. The node can be represented by the
airport name or name of the city. Check whether cities are connected
through flight or not. Compare the storage representation. */

#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    node *next;
};

void addEdge (string names[], int ind1, int ind2, node **adj) {
    node *newnode = new node;
    newnode->data = names[ind2];
    newnode->next = adj[ind1];
    adj[ind1] = newnode;
}

int findIndex (string names[], string city, int n) {
    for (int i = 0; i < n; i++) {
        if (names[i] == city) {
            return i;
        }
    }
    return -1;
}


int main () {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;
    string names[n];
    cout << "Enter the names of the cities:\n";
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    // adjacency matrix 
    int adjMatrix[n][n];

    // initializing all entries to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // adjacency list
    node *adjList[n];
    node **adj = adjList;

    // initializing all nodes to null 
    for (int i = 0; i < n; i++) {
        adjList[i] = nullptr;
    }

    cout << "Enter the flight paths (or -1 to terminate)\n";
    string city1, city2;
    int ind1, ind2, cost;
    while (true) {
        cout << "From: ";
        cin >> city1;
        if (city1 == "-1") {
            break;
        }
        cout << "To: ";
        cin >> city2;

        cout << "Cost: ";
        cin >> cost;

        ind1 = findIndex(names, city1, n);
        ind2 = findIndex(names, city2, n);
        if (ind1 == -1 || ind2 == -1) {
            cout << "Invalid input terminating the program\n";
            return 0;
        }

        adjMatrix[ind1][ind2] = cost;
        addEdge(names, ind1, ind2, adj);
    }

    vector <int> connectionCount(n, 0);

    // displaying adjacency matrix
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
            if (adjMatrix[i][j] == 0 && adjMatrix[j][i] == 0) {
                connectionCount[i]++;
            }
        }
        cout << "\n";
    }

    // displaying adjacency list 
    cout << "Adjacency list: \n";
    for (int i = 0; i < n; i++) {
        node *temp = adj[i];
        cout << names[i] << " -> ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null\n";
    }

    cout << "Isolated Cities: \n";
    for (int i = 0; i < n; i++) {
        if (connectionCount[i] == n) {
            cout << names[i] << endl;
        }
    }
}