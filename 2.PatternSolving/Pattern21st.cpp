//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int row = 1 ; row <= n ; row++){
        //for each row 
        for(int col = 1 ; col <= row ; col++){
            if(col == 1){
                cout << row;
            }
            else{
                cout << "*" << row;
            }
        }
        //after each row
        cout << endl;
    }
    for(int row = 1 ; row <= n ; row++){
        //for each row 
        for(int col = 1 ; col <= n - row + 1 ; col++){
            if(col == 1){
                cout << n - row + 1;
            }
            else{
                cout << "*" << n- row + 1;
            }
        }
        //after each row 
        cout << endl;
    }

}