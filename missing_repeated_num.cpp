#include <bits/stdc++.h>
using namespace std;

int findDuplicate(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return arr[i];
            }
        }
    }
    return -1;
}

int main()
{
    int arr[5] = {3, 1, 2, 5, 3};
    int n = 5;

    int gussianSum = (n * (n + 1)) / 2;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int duplicate = findDuplicate(arr, n);

    cout << duplicate << " ";
    cout << gussianSum - (sum - duplicate);

    return 0;
}