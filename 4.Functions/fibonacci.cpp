//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
void fibonacci(int n){
    int first = -1;
    int second = 1;
    while(n--){
        int sum = first + second;
        cout << sum << " ";
        first = second;
        second = sum;
    }
}
int main(){
    int n;
    cin >> n;
    fibonacci(n);
}