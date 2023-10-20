/* #include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[9] = {3,2,3,1,2,4,5,5,6};
    int n = 9;
    int k = 4;

    sort(arr, arr + n, greater<int>());

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << arr[k - 1];
    return 0;
} */

// Approach 2

#include <bits/stdc++.h>
using namespace std;

// Helper function to partition the array
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] >= pivot)
        { // Compare elements with the pivot
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to find the kth largest element using QuickSelect
int findKthLargest(vector<int> &arr, int low, int high, int k)
{
    if (k > 0 && k <= high - low + 1) // In range hai jb tk
    {
        int partitionIndex = partition(arr, low, high);

        // If the partition index is equal to k, we have found the kth largest element
        if (partitionIndex - low == k - 1)
        {
            return arr[partitionIndex];
        }

        // If the partition index is greater than k, search in the left subarray
        if (partitionIndex - low > k - 1)
        {
            return findKthLargest(arr, low, partitionIndex - 1, k);
        }

        // Otherwise, search in the right subarray
        return findKthLargest(arr, partitionIndex + 1, high, k - partitionIndex + low - 1);
    }

    // If k is out of range, return an appropriate value (e.g., -1)
    return -1;
}

int main()
{
    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // Find the 2nd largest element

    if (k >= 1 && k <= n)
    {
        vector<int> vec(arr, arr + n); //
        int kthLargest = findKthLargest(vec, 0, n - 1, k);
        cout << "The " << k << "nd largest element is: " << kthLargest << endl;
    }
    else
    {
        cout << "Invalid value of k." << endl;
    }

    return 0;
}
