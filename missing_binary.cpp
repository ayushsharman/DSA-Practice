#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(int arr[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int mid = (left + right) / 2;
        cout << arr[mid] << endl;
        if (arr[mid] == mid + 1)
        {
            // Missing number is on the right side
            left = mid + 1;
        }
        else
        {
            // Missing number is on the left side
            right = mid;
        }
    }

    // At this point, left is pointing to the missing number
    return left + 1; // Return the missing number itself
}

int main()
{
    int arr[7] = {1, 2, 4, 5, 6, 7, 8};
    int missingNumber = findMissingNumber(arr, 7);
    cout << "The missing number is: " << missingNumber << endl;
    return 0;
}
