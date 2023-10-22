#include <bits/stdc++.h>
using namespace std;

//Brute force: Shizuka's Algorithm
int singleNonDuplicate1(vector<int> &arr)
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

//Log N: Binary Search Method
int singleNonDuplicate2(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (mid % 2 == 1) {
            mid--; 
        }

        if (arr[mid] != arr[mid + 1]) {
            right = mid;
        } else {
            left = mid + 2;
        }
    }

    return arr[left];
}


int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5};

    int ans = singleNonDuplicate1(arr);

    cout << ans;
    return 0;
}
