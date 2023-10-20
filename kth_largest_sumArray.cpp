#include <bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> subArraySum;

    // Calculate subarray sums
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            subArraySum.push_back(sum);
        }
    }

    // Sort in descending order
    sort(subArraySum.begin(), subArraySum.end(), greater<int>());

    return subArraySum[k - 1];
}

int main()
{
    vector<int> arr = {10, -1, 7, -6, 5};
    int k = 3;
    int result = getKthLargest(arr, k);

    cout << "The " << k << "th largest subarray sum is: " << result << endl;
    return 0;
}
