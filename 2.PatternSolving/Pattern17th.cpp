//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int row = 1 ; row <= n ; row++){

        //for each row 
        //(n-row) Spaces
        for(int col = 1 ; col <= n-row ; col++){
            cout << " ";
        }
        //row stars
        for(int col = 1 ; col <= row ; col++){
            cout << "* ";
        }
        //after each row
        cout << endl;

    }
    for(int row = 1 ; row <= n ; row++){

        //for each row 
        //(row - 1) spaces
        
        for(int col = 1 ; col <= row - 1 ; col++){
            cout << " ";
        }
        
        //(n-row + 1) Stars
        for(int col = 1 ; col <= n - row + 1 ; col++){
            cout << "* ";
        }

        //after each row 
        cout << endl;

    }
}