//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
bool Search(int arr[3][3], int target, int row , int col){
    for(int i = 0 ; i < row ; i++){
        for(int j = 0; j < col ; j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return false;
}
int max(int a, int b){
    return (a > b) ? a : b;
}
void printColumnWiseSum(int arr[][3], int row , int column){
    int colSum = INT_MIN;
    for(int c = 0 ; c < column ; c++){
        int sum = 0;
        for(int r = 0 ; r < row ; r++){
            sum += arr[r][c];
        }
        colSum = max(sum , colSum);
        cout << sum << endl;
    }
    cout << "Max Column Sum : " << colSum << endl;
}
int main(){
    int arr[3][3] = {5, 1, 3, 4, 6, 8, 10, 9, 11};
    int target = 13;
    cout << Search(arr, 3, 3, 3) << endl;
    printColumnWiseSum(arr, 3, 3);

}