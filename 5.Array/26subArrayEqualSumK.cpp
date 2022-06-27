//Problem Link - https://leetcode.com/problems/subarray-sum-equals-k/
/* By Krishna Kumar */
#include<iostream>
using namespace std;
#include<unordered_map>
int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        ump[0] = 1;
        int currSum = 0;
        int count = 0;
        for(int i = 0 ; i < nums.size(); i++){
            currSum += nums[i];
            if(ump.find(currSum - k) != ump.end()){
                count += ump[currSum -k];
            }
            ump[currSum]++;
        }
        return count;
        
    }
int main(){
    
}