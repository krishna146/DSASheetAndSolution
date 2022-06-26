// Problem Link - https://leetcode.com/problems/maximum-product-of-word-lengths/
/* By Krishna Kumar */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int mapStringToInteger(string &str)
{
    int mappedInteger = 0;
    for (auto el : str)
    {
        int index = el - 'a';
        mappedInteger = mappedInteger | (1 << index);
    }
    return mappedInteger;
}
int maxProduct(vector<string> &words)
{
    vector<int> map;
    int maxpro = 0;
    for (auto el : words)
    {
        map.push_back(mapStringToInteger(el));
    }
    for (int i = 0; i < words.size() - 1; i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            if ((map[i] & map[j]) == 0)
            {
                int candidate = words[i].size() * words[j].size();
                maxpro = max(candidate, maxpro);
            }
        }
    }
    return maxpro;
}
int main()
{
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << maxProduct(words);
}