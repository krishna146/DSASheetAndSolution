//Problem Link - https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_10
/* By Krishna Kumar */
#include<iostream>
using namespace std;

int countDistinctWayToClimbStair(long long nStairs)
{
    //  Write your code here.
    if(nStairs == 0) return 1;
    if(nStairs < 0) return 0;
   
    return countDistinctWayToClimbStair(nStairs - 1) + countDistinctWayToClimbStair(nStairs - 2) ;
    
}
int main(){
    cout << countDistinctWayToClimbStair(5) << endl;
}