#include<iostream>
using namespace std;
int main(){
    int num;
    bool isPrime = true;
    cin >> num;
    for(int i = 2 ; i < num ; i++){
        if(num % i == 0){
            cout << "non prime" << endl;
            isPrime = false;
            break;
        }
    }
    if(isPrime){
        cout << "prime" << endl;
    }
}