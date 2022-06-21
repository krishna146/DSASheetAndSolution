#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    for(int row = 1; row <= n ; row++){
        //for each low

        //for first and last row
        if(row == n || row == 1){
            if(row ==1 )
                for(int col = 1 ; col <= n - row + 1 ; col++){
                    cout << col;
                }
            else
                cout << n;
          
        }
        //for remaining row
        else{
            
            cout << row ;
            //print spaces (n - row - 1)
            for(int col = 1 ; col <= n - row -1 ; col++){
                cout <<" " ;
            }
            cout << n ;
           
        }
        // after each row 
        cout << endl;

    }
}