//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<math.h>
int slowExponentiation(int a, int b){
int ans = 1;
    for(int i = 1 ; i <= b ; i++){
        ans = ans * a;
    }
    return ans;
}
//a^n
int fastExponentiation(int a, int n){
    int ans = 1;
    while(n > 0){
        if(n & 1) 
            ans = ans * a;
        a = a * a;
        n = n >> 1;
    }
    return ans;
    
}

using namespace std;
int main(){
    int a = 2;
    int b = 3;
    
    cout << fastExponentiation(a,b);
}