//Problem Link - https://leetcode.com/problems/k-closest-points-to-origin/
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Info{
public:
    int x;
    int y;
    float d;
    Info(int x, int y, float d){
        this -> x = x;
        this -> y = y;
        this -> d = d;
    }
    
};
class Cmp{
    public:
    bool operator()(Info* a, Info* b){
        return a -> d < b -> d;
    }
};
class Solution {
private: 
    float caculateDistanceFromOrigin(int x, int y){
        return sqrt(x*x + y*y);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Info*, vector<Info*> , Cmp> maxHeap;
        vector<vector<int>> ans(k);
        for(int i = 0 ; i < k ; i++){
            int x = points[i][0];
            int y = points[i][1];
            float dist = caculateDistanceFromOrigin(x, y);
            Info* temp = new Info(x, y, dist);
            maxHeap.push(temp);
        }
        for(int i = k ; i < points.size() ; i++){
            int x = points[i][0];
            int y = points[i][1];
            float dist = caculateDistanceFromOrigin(x, y);
            if(dist < maxHeap.top() -> d){
                maxHeap.pop();
                Info* temp = new Info(x, y , dist);
                maxHeap.push(temp);
            }
        }

        int index = 0;
        while(!maxHeap.empty()){
            Info* front = maxHeap.top();
            maxHeap.pop();
            ans[index].push_back(front -> x);
            ans[index].push_back(front -> y);
            index++;
        }
        return ans;
        
    }
};