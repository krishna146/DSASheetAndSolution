//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int main(){
    int row;
    cin >> row;
    int *rowcolumnSizeArray = new int[row]; 
    for(int index = 0 ; index < row ; index++){
        cin >> rowcolumnSizeArray[index];
    }
    //creating jagged array;
    int **jaggedArray = new int * [row];
    for(int index = 0; index < row; index++){
        jaggedArray[index] = new int[rowcolumnSizeArray[index]];
    }
    //inserting element
    for(int i = 0 ; i < row ; i++){
        for(int j = 0; j < rowcolumnSizeArray[i]; j++){
            cin >> jaggedArray[i][j];
        }
    }
    for(int i = 0 ; i < row ; i++){
        for(int j = 0; j < rowcolumnSizeArray[i]; j++){
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }
}