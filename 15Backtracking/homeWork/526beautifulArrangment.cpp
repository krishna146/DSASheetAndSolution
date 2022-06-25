//Problem Link - https://leetcode.com/problems/beautiful-arrangement/submissions/
/* By Krishna Kumar */
#include<iostream>
#include<vector>
using namespace std;
void countBeautifulArrangment(vector<int> &perm, int &index, int &count){
    if(index == perm.size()){
        count++;
        return;
    }
    for(int i = index ;i < perm.size() ; i++){
        swap(perm[i], perm[index]);
        if(perm[index] % index == 0 || index % perm[index] == 0){
            index++;
            countBeautifulArrangment(perm, index, count);
            index--;
        }
        swap(perm[i] , perm[index]);
    } 



}
int main(){
    int n = 6;
    int index = 1;
    int count = 0;
    vector<int> perm(n + 1);
    for(int i = 1 ; i <= n ; i++){
        perm[i] = i;
    }
    countBeautifulArrangment(perm, index, count);
    cout << count;
}