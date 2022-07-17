// Problem Link - https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        unordered_map<char, int> freq;
        queue<char> q;
        string ans;
        for (auto el : A)
        {
            freq[el]++;
            if (freq[el] == 1)
            {
                q.push(el);
            }
            while (!q.empty() && freq[q.front()] != 1)
            {
                q.pop();
            }
            if (q.empty())
                ans.push_back('#');
            else
                ans.push_back(q.front());
        }
        return ans;
    }
};