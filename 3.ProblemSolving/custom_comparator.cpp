//Problem Link - 
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    return a.second > b.second;
}
int main(){
    vector<pair<int, int>> p= {{12,8}, {10,2}, {9,1}, {8,6}, {7, 12}, {9, 13}, {8,5},{12, 7}, {4, 14}, {3, 17}};
    sort(p.begin(), p.end(), cmp);
    for(auto el : p){
        cout << el.first << " " << el.second << " ";
        cout << endl;
    }
}