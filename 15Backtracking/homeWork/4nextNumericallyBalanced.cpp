// Problem Link - https://leetcode.com/problems/next-greater-numerically-balanced-number/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    bool isNumericallyBalanced(int n)
    {
        string num = to_string(n);
        int arr[10] = {};
        for (auto el : num)
        {
            arr[el - '0']++;
        }
        for (int i = 0; i <= 9; i++)
        {
            if (arr[i] != 0 && i != arr[i])
                return false;
        }
        return true;
    }

public:
    int nextBeautifulNumber(int n)
    {
        int candidate = n + 1;
        while (true)
        {
            if (isNumericallyBalanced(candidate))
            {
                break;
            }
            candidate++;
        }
        return candidate;
    }
};