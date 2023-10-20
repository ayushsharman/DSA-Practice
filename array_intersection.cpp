/* #include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;

    vector<int> arr1(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr1[i];
    }
    vector<int> arr2(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr2[i];
    }

    vector<int> intersection;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr1[i] < arr2[j])
                break;

            if (arr1[i] == arr2[j])
            {
                intersection.push_back(arr1[i]);
                break;
            }
        }
    }

    for (int i = 0; i < intersection.size(); i++)
    {
        cout << intersection[i] << " ";
    }

    return 0;
}
 */

// Two Pointer approach

#include <bits/stdc++.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> ans;

    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return ans;
}

int main()
{
    // Example usage
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 4, 5, 6, 7};

    vector<int> result = findArrayIntersection(arr1, arr1.size(), arr2, arr2.size());

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
