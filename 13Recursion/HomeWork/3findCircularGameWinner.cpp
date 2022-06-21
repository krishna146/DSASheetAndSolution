//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<vector>
using namespace std;
int findCircularGameWinner(vector<int> &fr, int nIndex, int k){
    if(fr.size() == 1){
        return fr[0];
    }
    int indexToBeDeletd = (nIndex + k - 1) % fr.size();
    fr.erase(fr.begin() + indexToBeDeletd);
    nIndex = indexToBeDeletd  % fr.size();
    return findCircularGameWinner(fr, nIndex, k);

}
int main(){
    int n = 5;
    int k = 2;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        arr[i] = i + 1;
    }
    cout << findCircularGameWinner(arr, 0, k);

}