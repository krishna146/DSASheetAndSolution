// Problem Link - https://leetcode.com/problems/implement-trie-prefix-tree/
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

    bool search(string word)
    {
        int index = 0;
        TrieNode *temp = root;
        TrieNode *prev = temp;
        while (index < word.length())
        {
            char ch = word[index++];
            if (temp->children[ch - 'a'])
            {
                temp = temp->children[ch - 'a'];
            }
            else
            {
                return false;
            }
        }
        return temp->isTerminal;
    }
    bool startsWith(string prefix)
    {
        int index = 0;
        TrieNode *temp = root;
        while (index < prefix.length())
        {
            char ch = prefix[index++];
            if (temp->children[ch - 'a'])
            {
                temp = temp->children[ch - 'a'];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};