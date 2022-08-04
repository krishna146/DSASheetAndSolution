// Problem Link 1 - https://leetcode.com/problems/reorganize-string/
// Problem Link 2 - https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//using simple hashing and foor loop 
class Approach1
{
public:
    string reorganizeString(string s)
    {
        int arr[27] = {};
        int max = INT_MIN;
        int maxCharIndex;
        for (auto el : s)
        {
            arr[el - 96]++;
            if (arr[el - 96] > max)
            {
                max = arr[el - 96];
                maxCharIndex = el - 96;
            }
        }
        int index = 0;
        while (arr[maxCharIndex] > 0)
        {
            if (index >= s.size())
                return "";
            s[index] = maxCharIndex + 96;
            index += 2;
            arr[maxCharIndex]--;
        }
        for (int i = 1; i <= 26; i++)
        {
            char ch = i + 96;
            while (arr[i] > 0)
            {
                if (index >= s.size())
                    index = 1;
                s[index] = ch;
                index += 2;
                arr[i]--;
            }
        }
        return s;
    }
};
class Approach2 {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> maxHeap;
        int arr[27] = {};
        for(auto el: s){
            arr[el - 96]++;
        }
        for(int i = 1 ; i < 27 ; i++){
            if(arr[i] > 0){
                maxHeap.push({arr[i], i + 96});
            }
        }
        int index = 0;
        pair<int, int> block = {0, '$'};
        while(!maxHeap.empty()){
            pair<int, int> temp = maxHeap.top();
            maxHeap.pop();
            s[index++] = temp.second;
            temp.first--;
            if(block.first > 0){
                maxHeap.push(block);
            }
            block = temp;
            
        }
        if(block.first > 0)
            return "";
        return s;
        
    }
};