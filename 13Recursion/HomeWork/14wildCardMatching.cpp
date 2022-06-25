// Problem Link -
/* By Krishna Kumar */
#include <iostream>
#include <string>
using namespace std;
bool solve(string &s, int sIndex, string &p, int pIndex)
{
    if (p[pIndex] == '\0' && s[sIndex] == '\0')
        return true;
    if (s[sIndex] != '\0' && p[pIndex] == '\0')
        return false;
    bool ans = false;
    if (p[pIndex] == '*')
    {
        for (int i = sIndex; i <= s.size(); i++)
        {
            ans = solve(s, sIndex + i, p, pIndex + 1);
            if (ans == true)
            {
                break;
            }
        }
        return ans;
    }
    if (p[pIndex] == '?')
    {
        return solve(s, sIndex + 1, p, pIndex + 1);
    }
    if (p[pIndex] == s[sIndex])
    {
        return solve(s, sIndex + 1, p, pIndex + 1);
    }
    return false;
}
int main()
{
    string s = "abcabczzzde";
    string p = "*abc???de*";
    cout << solve(s, 0, p, 0) << endl;
}