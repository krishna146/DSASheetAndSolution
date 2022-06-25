#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int num){
     for(int i = 2 ; i * i <= num ; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}
long long primeProduct(long long L, long long R){
    long long mod = pow(10, 9) + 7;
    long long ans = 1;
    for(int i = L ; i <= R ; i++){
        if(isPrime(i)){
            ans = ans % mod * i % mod;
        }
    }
    return ans;
}
int main(){
    cout << primeProduct(1, 20) << endl;
}
