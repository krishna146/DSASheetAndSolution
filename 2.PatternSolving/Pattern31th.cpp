#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    //for row
    for(int row = 1 ; row <= n ; row++){

        //for each row , print n stars or we have n col

        for(int col = 1; col <= n ; col++){
            cout << "*";
        }
        cout << endl;
    }
}