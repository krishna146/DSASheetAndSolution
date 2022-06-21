//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int gcd(int a, int b){
    if(a == 0)
        return b;
    else if(b == 0)
        return a;
    else{
        while(a != b){
            if(a > b)
                a = a - b;
            else
                b = b - a;
        }
        return a;
    }
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
}