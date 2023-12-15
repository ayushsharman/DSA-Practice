// OJ: https://leetcode.com/problems/encode-and-decode-strings/
// Time: O(N)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Codec
{
public:
    string encode(vector<string> &strs)
    {
        string ans;
        for (string &str : strs)
        {
            for (char c : str)
            {
                if (c == '$')
                    ans.push_back(c);
                ans.push_back(c);
            }
            ans.push_back('$');
            ans.push_back('x');
        }
        return ans;
    }
    vector<string> decode(string s)
    {
        vector<string> ans;
        int i = 0, N = s.size();
        while (i < N)
        {
            string str;
            for (; i < N; ++i)
            {
                if (s[i] != '$')
                    str.push_back(s[i]);
                else if (i + 1 < N && s[i + 1] == '$')
                    str.push_back(s[i++]);
                else
                {
                    i += 2;
                    break;
                }
            }
            ans.push_back(str);
        }
        return ans;
    }
};