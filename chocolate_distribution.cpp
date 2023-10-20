#include <bits/stdc++.h>
using namespace std;

int chocolateDistribute1(int arr[], int n, int m)
{
    sort(arr, arr + n);

    int min = INT_MAX;

    for (int i = 0; i + m - 1 < n; i++)
    {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min)
            min = diff;
    }
    return min;
}


/*
int noOfPages(vector<int> &arr, int pages)

{

  int student = 1;

  long long pagesStudent = 0;

  for (int i = 0; i < arr.size(); i++)

  {

    if (pagesStudent + arr[i] <= pages)

      pagesStudent += arr[i];

    else

    {

      student += 1;

      pagesStudent = arr[i];
    }
  }

  return student;
}

int findPages(vector<int> &arr, int n, int m) {

  if (m > n)
    return -1;

  int low = *max_element(arr.begin(), arr.end());

  int high = accumulate(arr.begin(), arr.end(), 0);

  while (low <= high)

  {

    int mid = (low + high) / 2;

    int students = noOfPages(arr, mid);

    if (students > m)

      low = mid + 1;

    else

      high = mid - 1;
  }

  return low;
}

*/


int main()
{
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30,
                 40, 28, 42, 30, 44, 48, 43, 50};

    int m = 7;
    int n = sizeof(arr) / sizeof(int);

    int ans = chocolateDistribute1(arr, n, m);
    cout << ans;

    return 0;
}