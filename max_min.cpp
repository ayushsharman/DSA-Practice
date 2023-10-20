#include <bits/stdc++.h>
using namespace std;

int minNum(int arr[], int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

int maxNum(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int arraySort(int arr[], int n)
{

    sort(arr, arr + n);
}

int main()
{

    int arr[6] = {6, 21, 13, 4, 12, 30};
    int size = sizeof(arr) / sizeof(int);

    int min = minNum(arr, size);
    int max = maxNum(arr, size);

    /*
        Implement Sort to reduce complexity
        arraySort(arr, size);
        int min = arr[0];
        int max = arr[size - 1];

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl; */
    cout << min << " " << max;

    return 0;
}