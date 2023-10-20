#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

pair<int, int> findPair1(int arr[], int size, int targetSum)
{
    unordered_map<int, int> numToIndex;

    for (int i = 0; i < size; i++)
    {
        int complement = targetSum - arr[i];

        if (numToIndex.find(complement) != numToIndex.end())
        {
            // Found a pair that sums up to the target
            return make_pair(numToIndex[complement], i);
        }

        // Store the current element and its index
        numToIndex[arr[i]] = i;
    }

    // Return a pair with -1, -1 if no such pair is found
    return make_pair(-1, -1);
}

bool findPair(int arr[], int size, int target)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                cout << i << j << endl;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int arr[6] = {11, 15, 6, 8, 9, 10};
    int size = 6;
    int targetSum = 16;

     pair<int, int> result = findPair1(arr, size, targetSum);

     if (result.first != -1 && result.second != -1)
     {
         cout << "Pair found at indices: " << result.first << " and " << result.second << endl;
     }
     else
     {
         cout << "No pair found with the given sum." << endl;
     }

     

    // bool result = findPair(arr, size, targetSum);

    // cout << result << endl;

    return 0;
}
