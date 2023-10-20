#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;

    if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10))
    {
        return 0; //This condition was added to handle integar going out of range
    }

    while (n != 0)
    {
        int digit = n % 10;
        ans = ans * 10 + digit;
        n = n / 10;
    }

    cout << ans << endl;

    return 0;
}