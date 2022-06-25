//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
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
    printColumnWiseSum(arr, 3, 3);

}