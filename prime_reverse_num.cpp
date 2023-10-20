#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    // Handle special cases
    if (n <= 3)
    {
        return true;
    }

    // Check if n is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    // Check for prime using 6k +/- 1 optimization
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}

bool goodInteger(int x)
{
    int temp = x;
    int rem = 0;

    if (!isPrime(x))
        return false;

    int reversedNum = 0;
    while (temp)
    {
        int digit = temp % 10;
        reversedNum = reversedNum * 10 + digit;
        temp /= 10;
    }

    if (!isPrime(reversedNum))
        return false;

    return true;
}

int primeReversePrime(int l, int r)
{
    // Write your code here.
    int count = 0;
    for (int i = l; i < r; i++)
    {
        if (goodInteger(i) && i != 1)
        {
            cout << i << " ";
            count++;
        }
    }

    return count;
}

int main()
{
    int count = primeReversePrime(1, 21);
    cout << count;
    return 0;
}