#include <bits/stdc++.h>

using namespace std;

void heapify(vector<int> &arr, int size, int index)
{
    // Step 1: Check the Base condition
    if (index >= size)
        return;

    // Step 2: Point a pointer to the largest element to the root.
    int largest = index;

    // Step 3: find the index to the right and left child.
    int left = 2 * index;
    int right = 2 * index + 1;

    // Step 4: Check and update the largest value.
    if (left < size && arr[largest] < arr[left])
        largest = left;
    if (right < size && arr[largest] < arr[right])
        largest = right;

    // Step 5: Check If the largest value is updates
    if (largest != index)
    {
        // Step 6: swap the largest value and the root value.
        swap(arr[largest], arr[index]);

        // Step 7: Recursively update the updated tree.
        heapify(arr, size, largest);
    }
}
void buildHeap(vector<int> &arr, int size)
{
    // Step 1: Loop OVER ALL THE INTERNAL NODES AND APPLY HEAPIFY FROM BOTTOM-RIGHT.
    for (int i = size / 2; i >= 0; i--)
    {
        // Step 2: Apply Heapify
        heapify(arr, size, i);
    }
}

vector<int> heapSort(vector<int> &arr, int n)
{
    // Step 1: Heapify the array
    buildHeap(arr, n);

    // Step 2: Start removing all the elements one by one.
    while (n != 0)
    {
        n--;
        // Step 1: put the root node value to the last index.
        swap(arr[0], arr[n]);
        // Step 2: Heapify the newly formed heap
        heapify(arr, n, 0);
    }
    return arr;
}

int main()
{
    vector<int> arr = {21, 12, 3, 44, 7};
    int n = arr.size();

    vector<int> sortedArray = heapSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << sortedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
