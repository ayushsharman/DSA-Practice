#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    int sum = 0;
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // for (int i = 0; i < size; i++)
    // {
    //     if (5 == arr[i])
    //     {
    //         cout << "Found at " << i + 1 << endl;
    //     }
    // }

    // for (int i = 0; i < size; i++)
    // {
    //     sum += arr[i];
    // }
    // cout << sum;

    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start+=start+2;
        end=end-2;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
