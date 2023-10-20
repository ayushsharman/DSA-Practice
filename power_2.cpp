#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 1;

    for (int i = 0; i <= 30; i++)
    {

        // cout<<" ans "<<ans <<endl;
        if (ans == n)
        {
            cout << "true";
            return 0;
        }
        if (ans < INT_MAX / 2)
            ans = ans * 2;
    }
    cout << "false";
    return 0;
}