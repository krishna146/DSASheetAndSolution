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

        // 1 to row number
        for(int col = 1 ; col <= row ; col++){
            cout << col  ;
        }

        // (row -1) to 1 number
        for(int col = row - 1 ; col >= 1  ; col--){
            cout << col  ;
        }

        //after each row 
        cout << endl;
    }

}