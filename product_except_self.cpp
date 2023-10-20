
#include <iostream>
using namespace std;

int main()
{
    int arr1[4] = {1, 2, 3, 4};
    int size = 4;
    int arr2[size];
    int total_product = 1;
    int zeroCount = 0;

    // Calculate the product of all non-zero elements in arr1
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != 0)
        {
            total_product *= arr1[i];
        }
        else
        {
            zeroCount++;
        }
    }

    // If there is more than one zero, all elements in arr2 will remain zero.
    if (zeroCount <= 1)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr1[i] == 0)
            {
                arr2[i] = total_product;
            }
            else if (zeroCount == 1)
            {
                arr2[i] = 0;
            }
            else
            {
                arr2[i] = total_product / arr1[i];
            }
        }
    }

    // Output arr2
    for (int i = 0; i < size; i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}
