//Problem Link - https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class RandomizedCollection {
    private:
    unordered_map<int, vector<int>> ump;
    vector<pair<int, int> > elements;
public:
    RandomizedCollection() {
    }
    bool insert(int val) {
        bool isAbsent = ump.find(val) == ump.end();
        int valIndex = elements.size();
        int valPosInMapping = ump[val].size();
        ump[val].push_back(valIndex);
        elements.push_back({val, valPosInMapping});
        return isAbsent;
    }
    
    bool remove(int val) {
        bool isItemPresent = ump.find(val) != ump.end();
        if(isItemPresent){
            int lastIndex = elements.size() - 1;
            pair<int, int> lastIndexElementData = elements.back();
            int valIndex = ump[val].back();
            //updating lastIndexElementData
            ump[lastIndexElementData.first][lastIndexElementData.second] = valIndex;
            swap(elements[lastIndex], elements[valIndex]);
            elements.pop_back();
            ump[val].pop_back();
            if(ump[val].size() == 0){
                ump.erase(val);
            }
        }
        return isItemPresent;
        
    }
    
    int getRandom() {
        int randomIndex = rand() % elements.size();
        return elements[randomIndex].first;
    }
};