#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    for(int row = 1 ; row <= n ; row++){
        //for each row
        for(int col = 1 ; col <= row ; col++){
            cout << col ;

        }
        // after every row
        cout << endl;
    }
}