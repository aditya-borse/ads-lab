/* Q. Graph traversal: The area around the college and the prominent
landmarks of it are represented using graphs.
Write a menu driven C++ program to represent this as a graph using
adjacency matrix /list and perform DFS and BFS. */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;
int adjMatrix[MAX][MAX];

void bfs(int n)
{
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    cout << "BFS: ";
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[current][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

void dfs(int n)
{
    vector<bool> visited(n, false);
    stack<int> st;
    st.push(0);
    visited[0] = true;
    cout << "DFS: ";
    while (!st.empty())
    {
        int current = st.top();
        st.pop();
        cout << current << " ";
        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[current][i] == 1 && !visited[i])
            {
                st.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    cout << "Enter edges: ( or -1 to terminate)\n";
    int from, to;
    while (true)
    {
        cout << "From: ";
        cin >> from;
        if (from == -1)
        {
            break;
        }
        cout << "To: ";
        cin >> to;
        adjMatrix[from][to] = 1;
    }

    bfs(n);
    dfs(n);
}
