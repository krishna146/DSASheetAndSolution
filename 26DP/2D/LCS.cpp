//Problem Link - https://leetcode.com/problems/longest-common-subsequence/
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
private:
    int recursive(string &text1, string &text2, int i1, int i2){
        if(i1 == text1.length() || i2 == text2.length()){
            return 0;
        }
        int ans1;
        if(text1[i1] == text2[i2]){
            ans1 = 1 + recursive(text1, text2, 1 + i1, 1 + i2);
        }else{
            int option1 = recursive(text1, text2, i1, 1 + i2);
            int option2 = recursive(text1, text2, 1 + i1, i2);
            ans1 = max(option1, option2);
        }
        return ans1;
    }
    int topDown(string &text1, string &text2, int i1, int i2, vector<vector<int>> &dp){
        if(i1 == text1.length() || i2 == text2.length()){
            return 0;
        }
        if(dp[i1][i2] != -1) return dp[i1][i2];
        int ans1;
        if(text1[i1] == text2[i2]){
            ans1 = 1 + topDown(text1, text2, 1 + i1, 1 + i2, dp);
        }else{
            int option1 = topDown(text1, text2, i1, 1 + i2, dp);
            int option2 = topDown(text1, text2, 1 + i1, i2, dp);
            ans1 = max(option1, option2);
        }
        return dp[i1][i2] = ans1;
    }
    int bottomUp(string &text1, string &text2){
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for(int i1 = text1.length() - 1; i1 >= 0; i1--){
            for(int i2 = text2.length() - 1; i2 >= 0 ; i2--){
                int ans1;
                if(text1[i1] == text2[i2]){
                    ans1 = 1 + dp[i1 + 1][i2 + 1];
                }else{
                    int option1 = dp[i1][i2 + 1];
                    int option2 = dp[i1 + 1][i2];
                    ans1 = max(option1, option2);
                }
                dp[i1][i2] = ans1;
            }
        }
        return dp[0][0];
    }
    int spaceOptimization(string &text1, string &text2){
        vector<int> nextRowAns(text2.size() + 1, 0);
        for(int i1 = text1.length() - 1; i1 >= 0; i1--){
            int diagonalAns = 0;
            for(int i2 = text2.length() - 1; i2 >= 0 ; i2--){
                int ans1;
                if(text1[i1] == text2[i2]){
                    ans1 = 1 + diagonalAns;
                }else{
                    int option1 = nextRowAns[i2 + 1];
                    int option2 = nextRowAns[i2];
                    ans1 = max(option1, option2);
                }
                diagonalAns = nextRowAns[i2];
                nextRowAns[i2] = ans1;
                
            }
        }
        return nextRowAns[0];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        // return recursive(text1, text2, 0, 0);
        // vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        // return topDown(text1, text2, 0, 0, dp);
        // return bottomUp(text1, text2);
        return spaceOptimization(text1, text2);
    }
};