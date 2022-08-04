// Problem Link - https://leetcode.com/problems/replace-words/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class TrieNode
{
public:
    char ch;
    vector<TrieNode *> children;
    bool isTerminal = false;
    TrieNode(char ch) : children(26, NULL)
    {
        this->ch = ch;
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

public:
    void insertWords(string &word)
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
    string replaceByRoot(string &word)
    {
        string ans;
        int index = 0;
        TrieNode *temp = root;
        while (index < word.length())
        {
            char ch = word[index++];
            if (temp->children[ch - 'a'])
            {
                ans.push_back(ch);
                temp = temp->children[ch - 'a'];
                if (temp->isTerminal)
                    break;
            }
            else
            {
                return word;
            }
        }
        return ans;
    }
};
class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie *trie = new Trie();
        for (auto str : dictionary)
        {
            trie->insertWords(str);
        }
        string ans;
        for (int i = 0; i < sentence.size(); i++)
        {
            string temp;
            while (sentence[i] != ' ' && i < sentence.size())
            {
                temp.push_back(sentence[i]);
                i++;
            }
            string rootTemp = trie->replaceByRoot(temp);
            ans += rootTemp;
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};