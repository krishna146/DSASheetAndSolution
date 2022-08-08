// Problem Link - https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int longestKSubstr(string s, int k)
    {

        int arr[26] = {};
        int distinctChar = 0;
        int left = 0;
        int right = 0;
        int length = INT_MIN;
        int currLength = 0;
        while (right < s.length())
        {
            char ch = s[right];
            if (arr[ch - 'a'] == 0)
            {
                distinctChar++;
            }
            arr[ch - 'a']++;
            currLength++;
            while (distinctChar > k)
            {
                arr[s[left] - 'a']--;
                if (arr[s[left] - 'a'] == 0)
                {
                    distinctChar--;
                }
                currLength--;
                left++;
            }
            if (distinctChar == k)
            {
                length = max(length, currLength);
            }
            right++;
        }
        return length == INT_MIN ? -1 : length;
    }
};