#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    for(int row = 1 ; row <= n ; row++){
        //for each row, print stars = row ka no
        for(int col = 1 ; col <= row ; col++){
            cout << "*" ;

        }
        // after every row
        cout << endl;
    }
}