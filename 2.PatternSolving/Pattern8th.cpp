#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    for(int row = 1 ; row <= n ;row++){

        // for each row print (n- row + 1) stars
        for(int col = 1 ; col <= n - row + 1 ; col++){
            cout << col ;
        }
        cout << endl;
        
    }
}