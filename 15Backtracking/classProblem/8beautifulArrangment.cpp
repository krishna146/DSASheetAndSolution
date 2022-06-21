//Problem Link - https://leetcode.com/problems/beautiful-arrangement/submissions/
/* By Krishna Kumar */
#include<iostream>
#include<vector>
using namespace std;
bool isBeautiful(vector<int> &perm){
    for(int i = 1 ; i < perm.size(); i++){
        if(perm[i] % i != 0 && i % perm[i] != 0){
            return false;
        }
    }
    return true;
}
void countBeautifulArrangment(vector<int> &perm, int &index, int &count){
    if(index == perm.size()){
        if(isBeautiful(perm)){
            count++;
        }
        return;
    }
    for(int i = index ;i < perm.size() ; i++){
        swap(perm[i], perm[index]);
        index++;
        countBeautifulArrangment(perm, index, count);
        index--;
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