#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int size, int element)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else if (arr[mid] > element)
        {
            high = mid - 1;
        }
    }

    return -1; // Return -1 if element is not found
}

int main()
{
    cout << "Binary Search" << endl;

    int king[5] = {1, 2, 4, 6, 7};
    int even[6] = {2, 4, 6, 8, 12, 18};
    int a[10] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};

    int ans = binarySearch(king, 5, 7);
    cout << ans;
    ans = binarySearch(even, 6, 8);
    cout << ans;
    ans = binarySearch(a, 10, 8);
    cout << ans;

    return 0;
}
