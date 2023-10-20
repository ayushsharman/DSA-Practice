#include <bits/stdc++.h>
using namespace std;

void ap(int n)
{
    int term = 3 * n + 7;
    cout << term << endl;
}

void fibonacci(int n)
{
    int first = 0;
    int second = 1;
    int next_term = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            cout << first << " ";
            continue;
        }
        if (i == 2)
        {
            cout << second << " ";
            continue;
        }

        next_term = first + second;
        first = second;
        second = next_term;

        cout << next_term << " ";
    }
}

int main()
{
    fibonacci(8);
    return 0;
}