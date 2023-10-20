/* #include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int target = 12;
    int size = 5;

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - 1; j++)
        {
            for (int k = 2; k < size - 2; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    cout << i << j << k << endl;
                    cout << arr[i] + arr[j] + arr[k] << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
} */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int target = 12;
    int size = 5;

    for (int i = 0; i < size; i++)
    {
        int currentSum = 0;
        for (int j = i; j < size; j++)
        {
            currentSum += arr[j];
            if (currentSum == target)
            {
                cout << "Subarray found: ";
                for (int k = i; k <= j; k++)
                {
                    cout << arr[k] << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }

    cout << "Subarray not found" << endl;
    return 0;
}
