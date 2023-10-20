#include <bits/stdc++.h>
using namespace std;

int searchInRotatedArray(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[left] <= arr[mid]) //Sorted order mein hai ya nhi
        {
            if (arr[left] <= target && target < arr[mid]) //If target falls in the range
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (arr[mid] < target && target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};

    int target;
    cin >> target;

    // for (int i = 0; i < 7; i++)
    // {
    //     if (arr[i] == target)
    //     {
    //         cout << arr[i];
    //         return 0;
    //     }
    // }

    // cout << "Not found";

    int index = searchInRotatedArray(arr, 7, target);

    if (index != -1)
        cout << "Found at index " << index << ": " << arr[index] << endl;
    else
        cout << "Not found" << endl;

    return 0;
}