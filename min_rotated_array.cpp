#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int size)
{
    int low = 0;
    int high = size - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        cout << "This is mid " << arr[mid] << endl;

        if (arr[mid] < arr[high])
            high = mid;
        else if (arr[mid] > arr[high])
            low = mid + 1;
        else
            high--; // Handle the case when arr[mid] == arr[high], reduce the search space
    }

    return arr[low];
}

int main()
{

    int arr[3] = {3,1,2};
    int size = 3;

    int min = findMin(arr, size);
    cout << min;

    return 0;
}