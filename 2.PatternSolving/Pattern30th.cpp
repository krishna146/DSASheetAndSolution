#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    for(int row = 1 ; row <=n ; row++){
        //for each row print (row - 1)spaces and (n-row+1)stars
        
        //print (row - 1)spaces
        for(int col = 1 ; col <= row -1 ; col++){
            cout << " " ;
        }

        //print (n-row+1) stars
        for(int col = 1 ; col <= n - row + 1; col++){
            cout << "*" ;
        }
        
        //after each row    
        cout << endl;
    }
}