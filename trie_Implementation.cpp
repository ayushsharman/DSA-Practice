#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int terminalcount;
    int prefixWordCount;

    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
        terminalcount = 0;
        prefixWordCount = 0;
    }
};

class Trie
{

public:
    TrieNode *root;
    Trie() { root = new TrieNode('-'); }

    void insertWord(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            root->terminalcount++;
            root->prefixWordCount++;

            return;
        }

        char ch = word[0];
        int index = ch - 'a';

        TrieNode *child;
        if (root->children[index] != NULL)
            child = root->children[index];
        else
        {
            child = new TrieNode(ch);
            root->children[index] = child;
        }

        root->prefixWordCount++;
        insertWord(child, word.substr(1)); // recursion sambhal lega
    }

    void insert(string &word) { insertWord(root, word); }

    int countWordsEqualToUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->terminalcount;
        }

        char ch = word[0];
        int index = ch - 'a';

        TrieNode *child;
        if (root->children[index] != NULL)
            child = root->children[index];
        else
            return 0;

        return countWordsEqualToUtil(child, word.substr(1));
    }

    int countWordsEqualTo(string &word)
    {
        return countWordsEqualToUtil(root, word);
    }

    int countWordsStartingWithUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->prefixWordCount;
        }

        char ch = word[0];
        int index = ch - 'a';

        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];
        else
            return 0;

        return countWordsStartingWithUtil(child, word.substr(1));
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        return countWordsStartingWithUtil(root, word);
    }

    void eraseUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->terminalcount--;
            root->prefixWordCount--;
            root->isTerminal = false;

            return;
        }

        char ch = word[0];
        int index = ch - 'a';

        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
            root->prefixWordCount--;
        }
        else
            return;

        eraseUtil(child, word.substr(1));
    }

    void erase(string &word)
    {
        // Write your code here.
        eraseUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        char ch = word[0];
        int index = ch - 'a';

        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];
        else
            return false;

        return searchUtil(child, word.substr(1));
    }

    bool search(string &word)
    {
        return searchUtil(root, word);
    }
};
