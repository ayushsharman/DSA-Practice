#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum area in a histogram
int maxHistogramArea(vector<int> &heights)
{
    stack<int> s;
    int maxArea = 0;
    int i = 0;

    while (i < heights.size())
    {
        if (s.empty() || heights[i] >= heights[s.top()])
        {
            s.push(i);
            i++;
        }
        else
        {
            int tp = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, heights[tp] * width);
        }
    }

    while (!s.empty())
    {
        int tp = s.top();
        s.pop();
        int width = s.empty() ? i : i - s.top() - 1;
        maxArea = max(maxArea, heights[tp] * width);
    }

    return maxArea;
}

// Function to find the maximum rectangle area in a binary matrix
int maxRectangleArea(vector<vector<int>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
    {
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                heights[j] = 0;
            }
            else
            {
                heights[j]++;
            }
        }
        maxArea = max(maxArea, maxHistogramArea(heights));
    }

    return maxArea;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}};

    int result = maxRectangleArea(matrix);
    cout << "Maximum rectangle area in the binary matrix: " << result << endl;

    return 0;
}
