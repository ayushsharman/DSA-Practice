#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int n)
{
    if (n <= 0)
        return 0;
    return sum(arr, n - 1) + arr[n - 1];
}

int main()
{
    int arr[5] = {4, 6, 5, 5, 5};
    int n = 5;

    int ans = sum(arr, n);
    cout << ans;

    return 0;
}

/* #include <bits/stdc++.h>
using namespace std;

string reverseString(string s, int i, int j)
{

    if (i > j)
    {
        return s;
    }

    swap(s[i++], s[j--]);

    return reverseString(s, i, j);
}

int main()
{
    string a = "abccde";
    string rev = reverseString(a, 0, a.length() - 1);
    cout << rev;
    return 0;
} */