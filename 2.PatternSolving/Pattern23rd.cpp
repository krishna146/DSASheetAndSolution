//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    for(int row = 1 ; row <= n ; row ++){
        //for each row 
        if(row == 1 )
            cout << "*";
        else{
            cout << "*";
            for(int col = 1; col <= row -1 ; col++){
                cout << col ;
            }
            for(int col = row - 2 ; col >=1 ; col--){
                cout << col ;
            }
            cout << "*";

        }
    cout << endl;
    }
    for(int row = 1 ; row <= n - 1 ; row ++){
        //for each row 
        if(row == n -1 )
            cout << "*";
        else{
            cout << "*";
            for(int col = 1; col <= n - row -1 ; col++){
                cout << col ;
            }
            for(int col = n- row - 2 ; col >=1 ; col--){
                cout << col ;
            }
            cout << "*";

        }
    cout << endl;
    }
}