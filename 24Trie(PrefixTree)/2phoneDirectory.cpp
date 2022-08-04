// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class TrieNode
{
public:
    char data;
    bool isTerminal = false;
    vector<TrieNode *> children;
    TrieNode(char ch) : children(26, NULL)
    {
        this->data = ch;
    }
};
class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        this->root = new TrieNode('\0');
    }
    // insertion in trie
    void insert(string word)
    {
        int index = 0;
        TrieNode *temp = root;
        while (index < word.length())
        {
            char ch = word[index++];
            if (!temp->children[ch - 'a'])
            {
                temp->children[ch - 'a'] = new TrieNode(ch);
            }
            temp = temp->children[ch - 'a'];
        }
        temp->isTerminal = true;
    }

    vector<vector<string>> getAns(string &s)
    {
        vector<vector<string>> ans;
        TrieNode *temp = root;
        int index = 0;
        string prefix;
        while (index < s.length())
        {
            char ch = s[index];
            if (temp->children[ch - 'a'])
            {
                temp = temp->children[ch - 'a'];
                vector<string> tempAns;
                prefix.push_back(ch);
                findAllName(temp, tempAns, prefix);
                ans.push_back(tempAns);
            }
            else
            {
                while (index < s.length())
                {
                    vector<string> temp = {"0"};
                    ans.push_back(temp);
                    index++;
                }
            }
            index++;
        }

        return ans;
    }

private:
    void findAllName(TrieNode *temp, vector<string> &tempAns, string &prefix)
    {
        if (temp->isTerminal)
        {
            tempAns.push_back(prefix);
        }
        for (int i = 0; i < 26; i++)
        {
            if (temp->children[i])
            {
                prefix.push_back(i + 'a');
                findAllName(temp->children[i], tempAns, prefix);
                prefix.pop_back();
            }
        }
    }
};
class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie *t = new Trie();
        for (int i = 0; i < n; i++)
        {
            t->insert(contact[i]);
        }
        return t->getAns(s);
    }
};