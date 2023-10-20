#include <bits/stdc++.h>
using namespace std;

int main()
{
    char name[15] = "AyushSharma";

    // cout << name << endl;
    int i = 0;

    while (name[i] != '\0')
    {
        i++;
    }

    int end = i - 1;

    cout << i << endl;

    int start = 0;

    while (start < end)
    {
        swap(name[start++], name[end--]);
    }

    cout << name << endl;

    return 0;
}