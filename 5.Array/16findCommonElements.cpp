//Problem Link - https://practice.geeksforgeeks.org/problems/common-elements1132/1/
/* By Krishna Kumar */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void doIntersection(int A[],int B[], int n1, int n2, vector<int> &ans){
    int prev;
    int i = 0, j = 0;
    prev = min(A[i], B[j]);
    if(A[i] == B[j]){
        ans.push_back(A[i]);
        i++;
        j++;
        
    }
    while(i < n1 && j < n2){

        if(A[i] < B[j]){
            i++;
        }
        else if(A[i] > B[j]){
            j++;
        }
        else{
            if(A[i] != prev){
                ans.push_back(A[i]);
            }
            prev = A[i];
            i++;
            j++;
        }
    }

}
void printVector(vector<int> &arr){
    for(int i = 0 ; i < arr.size() ; i++){
        cout << arr[i] << endl;
    }
}
void printArray(int *arr, int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << endl;
    }
}
vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    //code here.
    vector<int> ans;
    doIntersection(A, B, n1, n2, ans);
    int size = ans.size();
    int *intermediate = new int[size];
    for(int i = 0 ;i < size ; i++){
        intermediate[i] = ans[i];
    }
    ans.clear();
    doIntersection(intermediate, C, size, n3, ans);
    printVector(ans);
    return ans;
}

int main(){
    int A[] = {1, 2, 3};
    int B[] = {1, 2, 3};
    int C[] = {1, 2, 3};
    commonElements(A, B, C, 3, 3, 3);
}