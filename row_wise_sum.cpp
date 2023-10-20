#include <bits/stdc++.h>
using namespace std;

int main()
{

    int arr[4][4] = {{4, 11}, {5, 3}, {3, 4}, {6, 4},};

    int sum[4] = {0};

    for (int i = 0; i < 4; i++)
    {

        // int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum[i] += arr[i][j];
        }

        // cout << sum << " ";
    }

    for (int i = 0; i < 4; i++)
    {
        cout << sum[i] << " ";
    }

    int maxi = INT_MIN;
    for (int i = 0; i < 4; i++)
    {
        if (sum[i] > maxi)
        {
            maxi = sum[i];
        }
    }

    cout << maxi;

    return 0;
}