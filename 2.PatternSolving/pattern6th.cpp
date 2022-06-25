//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n ; 
    for(int row = 1 ; row <= n ; row++){
        //for each row 

        //for first and last row
        if(row == 1 || row == n){
            // (n - row ) spaces
            for(int col = 1 ; col <= n - row ; col++){
                cout <<" ";
            }
            // row stars;
            for(int col = 1 ; col <= row ; col++){
                cout <<"* ";
            }

            //after each row 
            cout << endl;
            
        }
        //for rest row
        else{
            // (n - row ) spaces
            for(int col = 1 ; col <= n - row ; col++){
                cout <<" ";
            }
            cout << "*";
            // (n - row ) spaces
            for(int col = 1 ; col <= 2 * row  - 3 ; col++){
                cout <<" ";
            }
            cout << "*" ;

            //after each row 
            cout << endl;
            
        }
    }
}