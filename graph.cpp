#include <bits/stdc++.h>
using namespace std;

int main() {
    int graph[4][4] = {0}; // Initialize the adjacency matrix with all zeros

    // Create the directed edges
    graph[1][0] = 1; // a to b
    graph[2][1] = 1; // b to c
    graph[3][2] = 1; // c to d
    graph[0][3] = 1; // d to a

    // Output the adjacency matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
