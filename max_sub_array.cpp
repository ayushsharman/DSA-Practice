#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int size)
{
    int max_ending_here = arr[0];
    int max_so_far = arr[0];

    for (int i = 1; i < size; i++) //loop one se chlega
    {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main()
{
    int arr[6] = {-3, -2, 0, 9, -3, 1};
    int size = 6;

    int max_sum = maxSubarraySum(arr, size);

    cout << "Maximum subarray sum: " << max_sum << endl;

    return 0;
}


