#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    for(int row = 1 ; row <= n ; row++){
        //for each row
        int count =  1 + row * (row - 1) / 2;
        cout << count ++;
        for(int col = 1 ; col <= row - 1 ; col++){
            cout << "*" << count++ ;

        }
        // after every row
        cout << endl;
    }

    for(int row = 1 ; row <= n ; row++){
        //for each row
        int count =  1 + (n- row) * (n - row + 1) / 2;
        cout << count ++;
        for(int col = 1 ; col <= n - row  ; col++){
            cout << "*" << count++ ;

        }
        // after every row
        cout << endl;
    }

}