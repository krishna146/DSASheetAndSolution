#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    for(int row = 1 ; row <= n ; row++){
        //for each row print (n-row) spaces and row *


        //(n-row) spaces printing 
        for(int col = 1 ; col <= n - row ; col++){
            cout << " ";
        }
        
        //row star printing
        for(int col = 1 ; col <= row ; col++){
            cout << "*" ;
        }
        cout << endl;
    }
}