// Problem Link - https://leetcode.com/problems/insert-delete-getrandom-o1/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class RandomizedSet
{
private:
    unordered_map<int, int> ump;
    vector<int> elements;

public:
    RandomizedSet()
    {
    }
    bool insert(int val)
    {
        if (ump.find(val) != ump.end())
            return false;
        int valIndex = elements.size();
        elements.push_back(val);
        ump[val] = valIndex;
        return true;
    }

    bool remove(int val)
    {
        if (ump.find(val) == ump.end())
            return false;
        int valIndex = ump[val];
        int lastIndex = elements.size() - 1;
        swap(elements[valIndex], elements[lastIndex]);
        elements.pop_back();
        ump.erase(val);
        if (lastIndex != valIndex)
            ump[elements[valIndex]] = valIndex;
        return true;
    }

    int getRandom()
    {
        int randomNumber = rand();
        int randomIndex = (randomNumber % elements.size());
        return elements[randomIndex];
    }
};
