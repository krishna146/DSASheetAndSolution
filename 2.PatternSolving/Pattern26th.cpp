#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int count = 1;
    for(int row = 1 ; row <= n ; row++){
        //for each row

        // print (n - row + 1) stars
        for(int col = 1 ; col <= n - row + 1 ; col++){
            cout << "*";

        }

        // print 2*(row - 1) spaces;
        for(int col = 1 ; col <= 2 * (row  - 1); col++){
            cout << " ";

        }

        // print (n - row + 1) stars
        for(int col = 1 ; col <= n - row + 1 ; col++){
            cout << "*";

        }

        // after every row
        cout << endl;
    }
    for(int row = 1 ; row <= n ; row++){
        //for each row

        // print row stars
        for(int col = 1 ; col <= row ; col++){
            cout << "*";

        }

        // print 2*(n - row) spaces;
        for(int col = 1 ; col <= 2 * (n - row); col++){
            cout << " ";

        }


        // print row stars
        for(int col = 1 ; col <= row ; col++){
            cout << "*";

        }
        // after every row
        cout << endl;
    }

}