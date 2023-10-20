#include <bits/stdc++.h>
using namespace std;

int max_subarray_size(vector<int> arr, int k)
{
    int max_sum = 0;
    int window_sum = 0;

    for (int i = 0; i < k; i++)
    {
        window_sum += arr[i];
    }

    for (int i = k; i < arr.size(); i++)
    {
        window_sum = window_sum - arr[i - k] + arr[i];
        max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}

int main()
{
    vector<int> arr = {4, 2, 1, 7, 8, 1, 2, 8, 1, 0};
    int k = 3;

    int max = max_subarray_size(arr, k);

    cout << max << endl;

    return 0;
}
