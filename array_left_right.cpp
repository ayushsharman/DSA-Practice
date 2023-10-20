#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {1, 4, 3, 2, 3};
    int sum = 0;
    int leftSum = 0;

    // Calculate the total sum of all elements in the array
    for (int i = 0; i < 5; i++)
    {
        sum += arr[i];
    }

    // Iterate through the array to find the equilibrium point
    for (int i = 0; i < 5; i++)
    {
        // Subtract the current element from the total sum to get the right sum
        sum -= arr[i];

        cout << leftSum << " " << sum << endl;

        // Check if the left sum and right sum are equal
        if (leftSum == sum)
        {
            cout << i << endl;
            return 0;
        }

        // Add the current element to the left sum for the next iteration
        leftSum += arr[i];
    }

    // If no equilibrium point is found
    cout << "No equilibrium point found." << endl;

    return 0;
}
