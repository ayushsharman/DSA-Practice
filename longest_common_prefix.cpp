#include <bits/stdc++.h>
using namespace std;

/* string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";

    for (int i = 0; i < strs.size(); i++)
    {
        string temp1 = strs[i];
        string temp2 = strs[i + 1];

        for (int i = 0; i < temp1.length() || i < temp2.length(); i++)
        {
            char ch1 = temp1[i];
            char ch2 = temp2[i];

            if (ch1 == ch2)
                ans.push_back(ch1);
        }
    }

    return ans;
}

*/

// My solution corrected
string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";

    if (strs.empty())
    {
        return ans; // Return an empty string if the input vector is empty
    }

    // Find the minimum length string in the vector
    int minLen = INT_MAX;
    for (const string &str : strs)
    {
        minLen = min(minLen, (int)str.length());
    }

    cout << "So the min leng is " << minLen << endl;

    for (int i = 0; i < minLen; i++)
    {
        char commonChar = strs[0][i]; // Take the character from the first string
        cout << commonChar << " " << endl;

        for (int j = 1; j < strs.size(); j++)
        {
            cout << "inside the check for second string" << strs[j][i] << endl;
            if (strs[j][i] != commonChar)
            {
                return ans; // If a character doesn't match, return the current ans
            }
        }

        ans.push_back(commonChar);
    }

    return ans;
}

string longestCommonPrefix2(vector<string> &v)
{
    string ans = "";
    sort(v.begin(), v.end());
    int n = v.size();
    string first = v[0], last = v[n - 1];
    for (int i = 0; i < min(first.size(), last.size()); i++)
    {
        if (first[i] != last[i])
        {
            return ans;
        }
        ans += first[i];
    }
    return ans;
}

int main()
{
    vector<string> strs = {"flower", "flow", "fly"};

    cout << longestCommonPrefix(strs);
    return 0;
}