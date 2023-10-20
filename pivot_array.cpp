#include <bits/stdc++.h>
using namespace std;

int getPivot(int arr[], int size)
{
    int s = 0, e = size - 1;
    while (s < e)
    {
        int m = s + (e - s) / 2;

        if (arr[m] >= arr[0])
        {
            s = m + 1;
        }
        else
        {
            e = m;
        }
    }
    return s;
}

int main()
{
    int arr[5] = {8, 10, 17, 1, 3};

    cout << getPivot(arr, 5);
    return 0;
}