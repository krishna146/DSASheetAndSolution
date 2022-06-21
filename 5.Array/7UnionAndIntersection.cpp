//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
void printArray(int arr[], int size){
    for(int i = 0; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void printUnion(int arr1[], int arr2[], int size1, int size2){
    int i1 = 0, i2 = 0;
    while(i1 < size1  && i2 < size2 ){
        if(arr1[i1] < arr2[i2]){
            cout << arr1[i1] << " ";
            i1++;
        }
        else if(arr1[i1] > arr2[i2]){
            cout << arr2[i2] << " ";
            i2++;
        }
        else{
            cout << arr1[i1] << " ";
            i1++;
            i2++;
        }
    }
    while(i1 < size1 ){
        cout << arr1[i1] << " ";
        i1++;
    }
    while(i2 < size2 ){
        cout << arr2[i2] << " ";
        i2++;
    }
}
void printIntersection(int arr1[], int arr2[], int size1, int size2){
    int i1 = 0, i2 = 0;
    while(i1 < size1  && i2 < size2 ){
        if(arr1[i1] < arr2[i2]){
            i1++;
        }
        else if(arr1[i1] > arr2[i2]){
            i2++;
        }
        else{
            cout << arr1[i1] << " ";
            i1++;
            i2++;
        }
    }
  
}
int main(){
    int arr1[] = {1, 3, 8, 9, 11, 12};
    int size1 = sizeof(arr1) / sizeof(int);
    int arr2[] = {2, 3, 12, 19, 20 , 21 , 22};
    int size2 = sizeof(arr2) / sizeof(int);
    printUnion(arr1, arr2, size1, size2);
    cout << endl;
    printIntersection(arr1, arr2, size1, size2);
}