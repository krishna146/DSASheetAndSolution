#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    
    for(int row = 1 ; row <= n ; row++){
        //for each row 

        //spaces 
        for(int col = 1 ; col <= n - row ; col++){
            cout <<" ";
        }
        //stars
        for(int col = 1 ; col <= row ; col++){
            cout <<"* ";
        }
        //after each row 
        cout << endl;
    }
}