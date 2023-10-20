#include <bits/stdc++.h>
using namespace std;

string reverseWord(string str)
{
    int s = 0;
    int e = str.length() - 1;
    while (s <= e)
    {
        swap(str[s++], str[e--]);
    }

    return str;
}

void reverseOrder(const string &s)
{
    istringstream iss(s);
    vector<string> words;

    string word;
    string reversedWord;
    while (iss >> word)
    {
        reversedWord = reverseWord(word);
        words.push_back(reversedWord);
    }

    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i];
        if (i < words.size() - 1)
        {
            cout << " ";
        }
    }

    cout << endl;
}

int main()
{
    string s = "reverse krke dikhao";
    reverseOrder(s);
    return 0;
}
