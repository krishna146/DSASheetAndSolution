//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    
    for(int row = 1 ; row <= n ; row++){
        //for each row 

        //(n - row ) spaces 
        for(int col = 1 ; col <= n- row ; col++){
            cout <<" ";
        }

        // row to (2 * row - 1) number
        for(int col = row ; col <= 2* row - 1 ; col++){
            cout << col ;
        }

        // (2 * row - 2 ) to row number
        for(int col = 2 * row - 2 ; col >= row  ; col--){
            cout << col ;
        }

        //after each row 
        cout << endl;
    }

}