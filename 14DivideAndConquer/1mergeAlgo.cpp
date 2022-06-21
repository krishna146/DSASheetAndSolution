//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int * mergeAlgo(int arr1[], int arr2[], int n1, int n2){
    int *mergedArray = new int[n1 + n2];
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            mergedArray[k] = arr1[i];
            k++;
            i++;
        }
        else{
           mergedArray[k] = arr2[j];
            k++;
            j++;
        }
    }
    while(i < n1){
        mergedArray[k] = arr1[i];
        k++;
        i++;
    }
    while(j < n2){
        mergedArray[k] = arr2[j];
        k++;
        j++;
    }
    return mergedArray;

}
int main(){
    int arr1[] = {3, 5, 7, 9};
    int arr2[] = {2, 4, 6};
    int n1 = sizeof(arr1) / sizeof(int);
    int n2 = sizeof(arr2) / sizeof(int);
    int * mergedArray = mergeAlgo(arr1, arr2, n1, n2);
    for(int i = 0 ; i < n1 + n2 ; i++){
        cout << mergedArray[i] << " ";
    }
}