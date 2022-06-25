#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    for(int row = 1; row <= n ; row++){
        //for each low

        //for first and last row
        if(row == n || row == 1){
            for(int col = 1 ; col <= row ; col++){
                cout <<col;
            }
          
        }
        //for remaining row
        else{
            
            cout << "1" ;
            //print spaces
            for(int col = 1 ; col <= row - 2 ; col++){
                cout <<" " ;
            }
            cout << row ;
           
        }
        // after each row 
        cout << endl;

    }
}