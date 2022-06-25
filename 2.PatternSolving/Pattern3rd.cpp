#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    for(int row = 1; row <= n ; row++){
        //for each low

        //for first and last row
        if(row == n || row == 1){
            for(int col = 1 ; col <= n - row + 1 ; col++){
                cout <<"*";
            }
          
        }
        //for remaining row
        else{
            
            cout << "*" ;
            //print spaces
            for(int col = 1 ; col <= n - row -1 ; col++){
                cout <<" " ;
            }
            cout << "*" ;
           
        }
        // after each row 
        cout << endl;

    }
}