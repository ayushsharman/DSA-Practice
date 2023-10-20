#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int size)
{
    int max_ending_here = arr[0];
    int max_so_far = arr[0];

    for (int i = 1; i < size; i++)
    {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int maxProduct(int arr[], int size)
{
    int maxi = arr[0];
    int mini = arr[0];
    int ans = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < 0)
        {
            swap(maxi, mini);
        }
        maxi = max(arr[i], maxi * arr[i]);
        cout << maxi << endl;
        mini = min(arr[i], mini * arr[i]);
        cout << mini << endl;
        ans = max(ans, maxi);
    }
    return ans;
}

int main()
{
    int arr[4] = {2,3,-2,4};
    int size = 4;

    int max_product = maxProduct(arr, size);
    int max_sum = maxSubarraySum(arr, size);

    cout << "Maximum subarray sum: " << max_sum << endl;
    cout << "Maximum subarray product: " << max_product << endl;

    return 0;
}