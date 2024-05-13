/* Q. Activity on vertex(AOV) network: Sandy is a well organized person.
Every day he makes a list of things which need to be done and
enumerates them from 1 to n. However, some things need to be done
before others. Write a C++ code to find out whether Sandy can solve all
his duties and if so, print the correct order */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;
int adjMatrix[MAX][MAX];

map<int, int> countIndegree(int n)
{
    map<int, int> indegree;
    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }
    return indegree;
}

int findZeroIndegree(map<int, int> &indegree, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

void topologicalSort(int n)
{
    map<int, int> indegree = countIndegree(n);
    vector<int> order;
    queue<int> q;
    int current = findZeroIndegree(indegree, n);
    if (current != -1)
    {
        q.push(current);
        while (!q.empty())
        {
            current = q.front();
            order.push_back(current);
            q.pop();
            for (int i = 0; i < n; i++)
            {
                if (adjMatrix[current][i] == 1)
                {
                    indegree[i]--;
                    if (indegree[i] == 0)
                    {
                        q.push(i);
                    }
                }
            }
        }
        
        if (order.size() == n) {
            cout << "Yes, Sandy can solve all his duities.\n";
            cout << "Order: ";
            for (auto i : order) {
                cout << i << " ";
            }
            cout << endl;
        }
        else {
            cout << "No, Sandy cannot solve all his duities.\n";
        }
    }
    else {
        cout << "No, Sandy cannot solve all his duities." << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of tasks: ";
    cin >> n;
    cout << "Enter the edges: (or -1 to fininsh)" << endl;
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
    topologicalSort(n);
}