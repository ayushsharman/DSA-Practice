#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    int answer;

    if (n == 1)
    {
        return arr[0];
    }

    for (int i = 0; i < n - 1; i += 2)
    {
        // If adjacent elements are not equal then update answer
        if (arr[i] != arr[i + 1])
        {
            answer = arr[i];
            break;
        }
    }

    // Update answer
    if (arr[n - 2] != arr[n - 1])
    {
        answer = arr[n - 1];
    }

    return answer;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5};

    int ans = singleNonDuplicate(arr);

    cout << ans;
    return 0;
}
