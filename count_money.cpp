#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int Rs100, Rs50, Rs20, Rs1;

    switch (1)
    {
    case 1:
        Rs100 = n / 100;
        n = n % 100;
        cout << "No of 100 Rupee: " << Rs100 << endl;

    case 2:
        Rs50 = n / 50;
        n = n % 50;
        cout << "No of 50 Rupee: " << Rs50 << endl;

    case 3:
        Rs20 = n / 20;
        n = n % 20;
        cout << "No of 20 Rupee: " << Rs20 << endl;

    case 4:
        Rs1 = n / 1;
        n = n % 1;
        cout << "No of 1 Rupee: " << Rs1 << endl;
    }

       return 0;
}