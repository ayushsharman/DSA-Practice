#include <bits/stdc++.h>
using namespace std;


class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root , string word)
    {
        //base case
        if(word.length() == 0)
        {
            root->isTerminal=true;
            return;
        }

        int index = word[0]-'a';

        TrieNode * child;
        if(root->children[index] != NULL)
        {
            //present
            child = root->children[index];
        }
        else
        {
            //absent
            child = new TrieNode(word[0]);
            root->children[index]=child;
        }

        //recursive function
        insertUtil(child , word.substr(1));

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root , string word)
    {
        //base case
        if(word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0]-'a';
        TrieNode * child;

        if(root->children[index] != NULL)
        {
            //present
            child = root->children[index];
        }

        else
        {
            //absent
            return false;
        }

        //recursive function
        return searchUtil(child , word.substr(1));
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root,word);
    }

    bool prefixUtil(TrieNode* root , string word)
    {
        //base case
        if(word.length() == 0)
        {
            return true;
        }

        int index = word[0]-'a';
        TrieNode * child;

        if(root->children[index] != NULL)
        {
            //present
            child = root->children[index];
        }

        else
        {
            //absent
            return false;
        }

        //recursive function
        return prefixUtil(child , word.substr(1));
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return prefixUtil(root , prefix);
    }

    bool removeUtil(TrieNode* root, string word, int index) {
        if (index == word.length()) {
            if (root->isTerminal) {
                root->isTerminal = false;
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }

        int charIndex = word[index] - 'a';
        TrieNode* child = root->children[charIndex];

        if (child == NULL) {
            return false;
        }

        bool shouldDeleteChild = removeUtil(child, word, index + 1);

        if (shouldDeleteChild) {
            delete root->children[charIndex];
            root->children[charIndex] = NULL;
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != NULL) {
                    return false;
                }
            }
            return true;
        }

        return false;
    }

    void remove(string word) {
        removeUtil(root, word, 0);
    }
};

int main() {
    Trie trie;

    // Insert some words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("ball");

    // Search for words
    cout << "Search apple: " << trie.search("apple") << endl;
    cout << "Search app: " << trie.search("app") << endl;
    cout << "Search ball: " << trie.search("ball") << endl;
    cout << "Search bat: " << trie.search("bat") << endl;

    // Remove a word
    trie.remove("app");

    // Search again after removal
    cout << "Search app: " << trie.search("app") << endl;

    return 0;
}
