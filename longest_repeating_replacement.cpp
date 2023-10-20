#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k)
{
    int maxLength = 0;                  // Initialize the maximum length of substring
    int maxCount = 0;                   // Initialize the maximum count of a single character within the substring
    unordered_map<char, int> charCount; // To store the count of each character

    int i = 0; // Initialize the i of the current window

    for (int j = 0; j < s.length(); j++)
    {
        charCount[s[j]]++;                         // Update character count in the current window
        maxCount = max(maxCount, charCount[s[j]]); // Update maxCount

        // Check if the window size exceeds the allowed replacements
        if (j - i + 1 - maxCount > k)
        {
            charCount[s[i]]--; // Move the i of the window
            i++;
        }

        // Update maxLength for the current window
        maxLength = max(maxLength, j - i + 1);
    }

    return maxLength;
}

int main()
{
    string s = "ABC";

    int ans = characterReplacement(s, 2);
    cout << ans;

    return 0;
}