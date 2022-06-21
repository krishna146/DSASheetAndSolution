//Problem Link - 
/* By Krishna Kumar */
/* 
input:

   1   2   3   4   5 
   6   7   8   9   10
   11  12  13  14  15
   16  17  18  19  20

output : 1 2 3 4 5 10 9 8 7 6 11 12 13 14 15 20 19 18 17 16
*/


#include<iostream>
using namespace std;
void print2DSpirally(int matrix[][4], int row , int col){
    int count = 0;
    int startRow = 0;
    int endRow = row - 1;
    int startCol = 0;
    int endCol = col - 1;
    while(startRow <= endRow){
        for(int c = 0;  c<= endCol ; c++){
            cout << matrix[startRow][c] << " ";
        }
        startRow++;
        if(startRow > endRow) break;
        for(int c = endCol; c >= startCol ; c--){
            cout << matrix[startRow][c] << " ";
        }
        startRow++;
    }
    


}
int main(){
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7,8, 9, 10, 11, 12};
    print2DSpirally(arr, 3, 4);
   

}