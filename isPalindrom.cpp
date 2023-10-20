#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x)
{
    int rev = 0;
    int rem = 0;
    int num = x;

    while (num)
    {
        rem = num % 10;
        rev = 10 * rev + rem;
        num = num / 10;
    }

    cout << rev;

    if (rev == x)
        return true;
    else
        return false;
}

int main()
{
    int x = -121;
    if (isPalindrome(121))
        cout << "This is true" << endl;
    else
        cout << "No" << endl;
    return 0;
}