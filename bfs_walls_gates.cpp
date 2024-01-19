#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // Classic BFS: manually handle each direction
            if (check(row - 1, col, n, m) && grid[row - 1][col] == INT_MAX) {
                grid[row - 1][col] = grid[row][col] + 1;
                q.push({row - 1, col});
            }
            
            if (check(row + 1, col, n, m) && grid[row + 1][col] == INT_MAX) {
                grid[row + 1][col] = grid[row][col] + 1;
                q.push({row + 1, col});
            }
            
            if (check(row, col - 1, n, m) && grid[row][col - 1] == INT_MAX) {
                grid[row][col - 1] = grid[row][col] + 1;
                q.push({row, col - 1});
            }
            
            if (check(row, col + 1, n, m) && grid[row][col + 1] == INT_MAX) {
                grid[row][col + 1] = grid[row][col] + 1;
                q.push({row, col + 1});
            }
        }
    }

private:
    bool check(int i, int j, int n, int m) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
};
