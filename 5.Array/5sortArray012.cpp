//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
void sortArray012(int arr[], int size){
    //Approach 1
    
   int low = 0;
   int mid = 1;
   int right = size - 1;
   while(mid <= right){
       if(arr[mid] == 0){
           swap(arr[low] , arr[mid]);
           low++;
       }
       else if(arr[mid] == 2){
           swap(arr[mid], arr[right]);
           right--;
       }
       else{
           mid++;
       }
   }


   //Approach2: 

    // int zero = 0;
    // int one = 0;
    // int two = 0;
    // int i = 0;
    // while(i < size){
    //     if(arr[i] == 0) zero++;
    //     else if(arr[i] == 1) one++;
    //     else two++;
    //     i++;
    // }
    // int j = 0;
    // while(zero--){
    //     arr[j] = 0;
    //     j++;
    // }
    // while(one--){
    //     arr[j] = 1;
    //     j++;
    // }
    // while(two--){
    //     arr[j] = 2;
    //     j++;
    // }

}
void printArray(int arr[], int size){
    for(int i = 0; i < size ; i++){
        cout << arr[i] << endl;
    }
}
int main(){
    int arr[] = {1, 0, 2, 2, 0, 1, 1};
    sortArray012(arr, 7);
    printArray(arr, 7);
}
