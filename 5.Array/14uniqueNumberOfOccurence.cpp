//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool uniqueOccurrences(vector<int>& arr) {
    
    unordered_map<int , int> elementFrequency;
    for(auto el : arr){
        elementFrequency[el]++;
    }
    
    unordered_map<int, int> occurenceFrequency;
    for(auto el: elementFrequency){
        occurenceFrequency[el.second]++;
    }
    for(auto el : occurenceFrequency){
        if(el.second > 1)
            return false;
    }
    return true;
    
}
int main(){
    vector<int> arr = {1, 2, 3, 1, 3, 3, 4, 4, 4, 4};
    cout << uniqueOccurrences(arr);
}