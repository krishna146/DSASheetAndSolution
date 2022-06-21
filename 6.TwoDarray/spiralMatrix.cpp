//Problem Link - https://leetcode.com/problems/spiral-matrix/
/* By Krishna Kumar */
#include<iostream>
using namespace std;
void print2DSpirally(int matrix[][4], int row , int col){
    int count = 0;
    int startRow = 0;
    int endRow = row - 1;
    int startCol = 0;
    int endCol = col - 1;
    while(count < row * col)
    {
        for(int c = startCol; c <= endCol ; c++){
            cout << matrix[startRow][c] << " ";
            count++;
        }
        startRow++;
        if(count >= row * col ) break;
        for(int r = startRow ; r <= endRow ; r++){
            cout << matrix[r][endCol] << " ";
            count++;
        }
        endCol--;
        if(count >= row * col ) break;
        for(int c = endCol; c >= startCol ; c--){
            cout << matrix[endRow][c] << " ";
            count++;
        }
        endRow--;
        if(count >= row * col ) break;
        for(int r = endRow ; r >= startRow ; r--){
            cout << matrix[r][startCol] << " ";
            count++;
        }
        startCol++;
    }


}
int main(){
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7,8, 9, 10, 11, 12};
    
    print2DSpirally(arr, 3, 4);
   

}