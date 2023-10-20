#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int min_price = prices[0];
    int maxprof = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        maxprof = max(maxprof, prices[i] - min_price);
        min_price = min(prices[i], min_price);
    }

    return maxprof;
}

int main()
{
    int arr[3] = {2, 4, 1};

    int minIndex = 0;

    int n = sizeof(arr) / sizeof(int);

    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            minIndex = i;
        }
    }

    cout << min;
    int ans = 0;

    for (int i = minIndex; i < n; i++)
    {
        if (arr[i] - min > ans)
        {
            ans = arr[i] - min;
        }
    }

    cout << ans;

    return 0;
}