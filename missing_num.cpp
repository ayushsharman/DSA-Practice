#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {2, 1, 3, 0, 5};

    int n = 5;
    // ans should be 4

    /*  sort(arr, arr + 5);
     int count = 0;

     for (int i = 0; i < 5; i++)
     {
         if (count == arr[i])
         {
             count++;
         }
         else
         {
             cout << count;
         }
     } */

    // Approach 2

    int gussianSum = (n * (n + 1)) / 2;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    cout << gussianSum << " " << sum << " ";
    cout << gussianSum - sum;

    return 0;
}