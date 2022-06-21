//Problem Link - https://leetcode.com/problems/rotate-image/
/* By Krishna Kumar */
#include<iostream>
using namespace std;
void transpose(int arr[][4], int row , int col){
    for(int i = 0 ; i < row ; i++){
        for(int j = i + 1; j < col ; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
}
void reverseColumn(int arr[][4], int row , int col){
    for(int c = 0; c < col / 2 ; c++){
        for(int r = 0 ; r < row ; r++){
            swap(arr[r][c], arr[r][col - c - 1]);
        }
    }
}
void print2DArray(int arr[][4], int row , int col){
    for(int i = 0 ; i < row ; i++){
        for(int j = 0; j < col ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int arr[4][4] = {5, 1, 3, 4, 6, 8, 10, 9, 11, 12, 18, 19, 29, 39, 31, 32};
    transpose(arr, 4, 4);
    reverseColumn(arr, 4, 4);
    print2DArray(arr, 4, 4);
   

}