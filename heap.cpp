// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << ' ';
        }
    }

    void deletion()
    {
        if (size == 0)
        {
            cout << "Can't do";
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex <= size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }

            else if (rightIndex <= size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }

            else
            {
                return;
            }
        }
    }

    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (arr[largest] < arr[left])
        {
            largest = left;
        }

        if (arr[largest] < arr[right])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void buildHeap(int arr[], int size){
    for(int i = (size/2 - 1); i >= 0; i--){
        // Step 2: Apply Heapify
        heapify(arr, size, i);
    }
}
};

int main()
{
    // Write C++ code here
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.deletion();
    h.print();
    return 0;
}