//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    for(int row = 1; row <= n ; row ++){

        //for each row
        
        // (2 * n - row - 1) stars
        for(int col = 1 ; col <= 2 * n - row -1 ; col++){
            cout << "*";
        }
        //print row no. with stars
        for(int col = 1; col <= row ; col++){
            cout << row << "*";
        }

        // (2 * n - row - 2) stars
        for(int col = 1 ; col <= 2 * n - row -1 ; col++){
            cout << "*";
        }
        //after each row
        cout << endl;
    }
    int z;
    cin >> z;
}