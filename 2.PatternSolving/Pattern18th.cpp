//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int row = 1 ; row <= n; row ++){
        //for each row

        //(n-row) spaces
        for(int col = 1 ; col <= n - row ; col++){
            cout << " ";
        }
        //star
        cout << "*";

        // (2 * row - 3) spaces
        for(int col = 1 ; col <= 2 * row - 3 ; col++){
            cout << " ";
        }

        //star
        if(row != 1){
            cout << "*";
        }
        cout << endl;
    }
    for(int row = 1 ; row <= n; row ++){
        //for each row

        //(row - 1) spaces
        for(int col = 1 ; col <= row -1 ; col++){
            cout << " ";
        }
        cout << "*";

        //2*(n - row + 1) - 3 spaces
        for(int col = 1 ; col <= 2 *(n- row + 1) - 3 ; col++){
            cout << " ";
        }
        if(row != 5){
            cout << "*";
        }
        cout << endl;
    }
}