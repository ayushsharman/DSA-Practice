#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Convert the vector to a new vector for sorting
    vector<int> vec(arr.begin(), arr.end());

    // Sort the vector
    sort(vec.begin(), vec.end());

    set<int> element; //All the elements
    set<int> occur; //Kitni baar arha koi element 

    for (int i = 0; i < size; i++)
    {
        element.insert(vec[i]);
    }

    int ac = 1;
    for (int i = 0; i < size - 1; i++)
    {
        if (vec[i] == vec[i + 1])
        {
            ac++;
        }
        else
        {
            occur.insert(ac);
            ac = 1;
        }
    }
    occur.insert(ac);

    if (element.size() == occur.size())
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}
