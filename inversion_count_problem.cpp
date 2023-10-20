#include <bits/stdc++.h>
using namespace std;

void getArray(int size, int *arr)
{
    cout << "Enter the elements " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void traversal(int size, int *arr)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int merge(int *arr, int left, int mid, int right)
{
    int l1 = mid - left + 1;
    int l2 = right - mid;

    int subArray1[l1];
    int subArray2[l2];

    for (int i = 0; i < l1; i++)
    {
        subArray1[i] = arr[left + i];
    }

    for (int i = 0; i < l2; i++)
    {
        subArray2[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    int count = 0; // Initialize the inversion count.

    while (i < l1 && j < l2)
    {
        if (subArray1[i] <= subArray2[j])
        { // Use <= to count equal elements as well.
            arr[k] = subArray1[i];
            i++;
        }
        else
        {
            arr[k] = subArray2[j];
            j++;
            // If an element from subArray1 is greater than an element from subArray2,
            // it means there are (l1 - i) remaining elements in subArray1 that are greater,
            // so we increment the inversion count accordingly.
            count += (l1 - i);
        }
        k++;
    }

    while (i < l1)
    {
        arr[k] = subArray1[i];
        i++;
        k++;
    }

    while (j < l2)
    {
        arr[k] = subArray2[j];
        j++;
        k++;
    }

    return count; // Return the inversion count for this merge operation.
}

int mergeSort(int *arr, int left, int right)
{
    int count = 0; // Initialize the inversion count for this recursive call.

    if (left < right)
    {
        int mid = (left + right) / 2;

        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);
        count += merge(arr, left, mid, right);
    }

    return count; // Return the total inversion count for this mergeSort call.
}

int main()
{
    int arr[5] = {1, 20, 6, 4, 5};
    int size = 5;

    traversal(size, arr);
    int inversionCount = mergeSort(arr, 0, size - 1);
    traversal(size, arr);

    cout << "Inversion Count: " << inversionCount << endl;

    return 0;
}
