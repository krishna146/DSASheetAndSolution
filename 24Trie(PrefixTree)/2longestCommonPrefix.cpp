// Problem Link - https://leetcode.com/problems/longest-common-prefix/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// Using Trie Data Structure TC = O(MN) SC = O(MN)
class TrieNode
{
public:
    char ch;
    vector<TrieNode *> children;
    bool isTerminal;
    int childCount;
    TrieNode(char ch) : children(26, NULL)
    {
        this->ch = ch;
        this->isTerminal = false;
        this->childCount = 0;
    }
};
class Approach1
{

private:
    TrieNode *root;
    void insertWord(string &word)
    {
        int index = 0;
        TrieNode *temp = root;
        while (index < word.length())
        {
            char ch = word[index++];
            int idx = ch - 'a';
            if (!temp->children[idx])
            {
                temp->children[idx] = new TrieNode(ch);
                temp->childCount++;
            }
            temp = temp->children[idx];
        }
        temp->isTerminal = true;
    }

public:
    Approach1()
    {
        this->root = new TrieNode('\0');
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        // your code here
        for (int i = 0; i < strs.size(); i++)
        {
            insertWord(strs[i]);
        }
        string str = strs[0];
        string ans;
        TrieNode *temp = root;
        for (auto el : str)
        {
            if (temp->childCount > 1 || temp->isTerminal)
            {
                break;
            }
            ans += el;
            temp = temp->children[el - 'a'];
        }
        if (ans.empty())
            return "";
        return ans;
    }
};
// Using Two For Loop : TC = O(MN) SC = O(1) M: max length of any string N : No OF String
class Approach2
{
    string longestCommonPrefix(vector<string> &strs)
    {
        string &temp = strs[0];

        for (int idx = 0; idx < temp.length(); idx++)
        {
            for (int i = 1; i < strs.size(); i++)
            {
                if (strs[i][idx] != temp[idx])
                {
                    return temp.substr(0, idx);
                }
            }
        }
        return temp;
    }
};