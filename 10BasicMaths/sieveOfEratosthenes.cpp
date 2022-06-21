//Problem Link - https://leetcode.com/problems/count-primes/
/* By Krishna Kumar */
#include<iostream>
#include<vector>
using namespace std;
    int countPrimes(int n) {
        int count = 0;
        vector<bool> prime(n + 1, true);
        prime[0] = false;
        prime[1] = false;
        for(int i = 2 ; i < n ; i++){
            if(prime[i]){
                count++;
                for(int j = 2 * i; j <n ; j = j + i){
                    prime[j] = false;
                }
            }
        }
        return count;
        
    }
int main(){
    cout << countPrimes(2) << endl;
}