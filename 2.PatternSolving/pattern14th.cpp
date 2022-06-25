//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    
    for(int row = 1 ; row <= n ; row++){
        //for each row 

        //A to A + row - 1
        for(char col = 'A'; col <= 'A' + row - 1; col++){
            cout << col << " " ;
        }

        // (row - 1) to 1
        for(char col = 'A' + row - 2 ; col >= 'A'  ; col--){
            cout << (char) col << " " ;
        }

        //after each row 
        cout << endl;
    }

}