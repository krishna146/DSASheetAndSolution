//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
long long primeProduct(long long L, long long R){
    long long mod = pow(10, 9) + 7;
    int count = 0;
    vector<bool> prime(R + 1, true);
    prime[0] = false;
    prime[1] = false;
    for(int i = 2 ; i <= R ; i++){
        if(prime[i]){
            for(int j = 2 * i; j <= R ; j = j + i){
                prime[j] = false;
            }
        }
    }
    long long ans = 1;
    for(int i = L ; i <= R ; i++){
        if(prime[i]){
            ans = ans % mod * i % mod;
        }
    }
    return ans;
}
int main(){
    cout << primeProduct(1, 20);
}