#include <bits/stdc++.h>
using namespace std;

int findDuplicateXOR(int arr[], int n) // Works in the case if the every number occurs atleast once
{
  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    ans = ans ^ arr[i];
  }
  for (int i = 1; i < n; i++)
  {
    ans = ans ^ i;
  }
  return ans;
}

int findDuplicate(int arr[], int n)
{
  unordered_map<int, bool> seen;

  for (int i = 0; i < n; i++)
  {
    if (seen[arr[i]])
    {
      return arr[i];
    }
    seen[arr[i]] = true;
  }

  return -1;
}

int main()
{
  int arr[5] = {3, 1, 2, 4, 4};

  int duplicate = findDuplicate(arr, 5);

  if (duplicate != -1)
  {
    cout << "The duplicate element is: " << duplicate << endl;
  }
  else
  {
    cout << "There is no duplicate element in the array." << endl;
  }

  return 0;
}