#include <bits/stdc++.h>
using namespace std;

vector<int> mergeTwoArrays(const vector<int> &arr1, const vector<int> &arr2)
{
    vector<int> mergedArray;
    int i = 0, j = 0;

    for (auto i : arr1)
        mergedArray.push_back(i);
    for (auto i : arr2)
        mergedArray.push_back(i);
    return mergedArray;
}

vector<int> mergeKArrays(vector<vector<int>> &arrays)
{
    if (arrays.empty())
    {
        return vector<int>();
    }

    vector<int> mergedArray = arrays[0];

    for (int i = 1; i < arrays.size(); i++)
    {
        mergedArray = mergeTwoArrays(mergedArray, arrays[i]);
    }

    return mergedArray;
}

int main()
{
    vector<vector<int>> arrays = {
        {1, 3, 5},
        {2, 4, 6},
        {0, 7, 8}};

    vector<int> mergedArray = mergeKArrays(arrays);

    cout << "Merged Array: ";
    for (int num : mergedArray)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
