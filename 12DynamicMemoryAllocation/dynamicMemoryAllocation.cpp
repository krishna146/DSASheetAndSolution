//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int main(){
    //dynamic 1d memory
    // int n ;
    // cout << "Enter the value of n ";
    // cin >> n;
    // int *arr = new int[n];
    // for(int i = 0; i < n; i++){
    //     cin >> n;
    // }
    // cout << "printing the array" << endl;
    // for(int i = 0; i < n; i++){
    //     cout << arr[i] << " ";
    // }
    // //deleting the 1d array
    // delete []arr;
    //dynamic 2d array
    int  m;
    cin >> m;
    int **array2d = new int *[m];
    int n;
    cin >> n;
    for(int i = 0 ; i< m; i++){
        array2d[i] = new int[n];
        
    }
    for(int i = 0 ; i < m ; i++){
        for(int j = 0; j< n; j++){
            cin >> array2d[i][j];
        }
    }
    //printing 2d array
    for(int i = 0 ; i < m ; i++){
    for(int j = 0; j< n; j++){
        cout << array2d[i][j] << " ";
    }
    cout << endl;
}
    
    //deleting memory
    //deleting each 1d array
    for(int i = 0 ; i< m; i++){
        delete []array2d[i];
        
    }   
    //deleting each 1d array
    delete []array2d; 

}