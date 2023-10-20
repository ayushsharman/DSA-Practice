/* #include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[12] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size = 12;

    int water = 0;
    int leftIndex = 0;
    int middleIndex = leftIndex + 1;
    int rightIndex = middleIndex + 1;

    for (int i = 1; i < size - 1; i++)
    { // Start from index 1 and go up to size - 2
        if (arr[leftIndex] > arr[middleIndex])
        {
            if (arr[middleIndex] < arr[rightIndex])
            {
                int min_height = min(arr[leftIndex], arr[rightIndex]);
                water += min_height - arr[middleIndex];
            }
            else
            {
                rightIndex++;
            }
        }
        else
        {
            leftIndex = i; // Move the leftIndex to the current index
            middleIndex = leftIndex + 1;
            rightIndex = middleIndex + 1;
        }
    }

    cout << water << endl;

    return 0;
}
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[12] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size = 12;

    int water = 0;
    int leftIndex = 0;
    int rightIndex = size - 1; // Initialize rightIndex to the last element

    int leftMax = 0;  // Initialize leftMax to 0
    int rightMax = 0; // Initialize rightMax to 0

    while (leftIndex < rightIndex)
    {
        if (arr[leftIndex] < arr[rightIndex])
        {
            if (arr[leftIndex] > leftMax)
            {
                leftMax = arr[leftIndex];
            }
            else
            {
                water += leftMax - arr[leftIndex];
            }
            leftIndex++;
        }
        else
        {
            if (arr[rightIndex] > rightMax)
            {
                rightMax = arr[rightIndex];
            }
            else
            {
                water += rightMax - arr[rightIndex];
            }
            rightIndex--;
        }
    }

    cout << water << endl;

    return 0;
}
