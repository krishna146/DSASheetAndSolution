//Problem Link - https://practice.geeksforgeeks.org/problems/coin-change2448/1
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int countWays(int coins[],int size,  int totalAmount,int parent){
    if(totalAmount == 0)
        return 1;
    if(totalAmount < 0)
        return 0;
    int ways = 0;
    for(int i = parent; i < size ; i++){
        ways  += countWays(coins, size , totalAmount - coins[i] , i);
    }
    return ways;
}
int main(){
    int coins[] = {1, 2};
    int size = sizeof(coins) / sizeof(int);
    int totalAmount = 4;
    cout << countWays(coins,size,  totalAmount, 0);
}