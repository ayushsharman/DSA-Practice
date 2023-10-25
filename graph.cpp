#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{

    vector<int> graph[n];

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);
        for (int j = 0; j < graph[i].size(); j++)
        {
            adj[i].push_back(graph[i][j]);
        }
    }
    return adj;
}

int main()
{
    int graph[4][4] = {0}; // Initialize the adjacency matrix with all zeros

    // Create the directed edges
    graph[1][0] = 1; // a to b
    graph[2][1] = 1; // b to c
    graph[3][2] = 1; // c to d
    graph[0][3] = 1; // d to a

    // Output the adjacency matrix
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
