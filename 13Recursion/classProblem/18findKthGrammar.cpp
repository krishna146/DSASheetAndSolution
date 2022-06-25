//Problem Link - https://leetcode.com/problems/k-th-symbol-in-grammar/
/* By Krishna Kumar */
#include<iostream>
#include<math.h>
using namespace std;
int kthGrammar(int n, int k) {
    if(n == 1){
        return 0;
    }
    if(k <= pow(2, n - 2)){
        return kthGrammar(n - 1, k);
    }
    return !kthGrammar(n - 1, k - pow(2, n - 2));
    
}
int main(){
    int n = 5;
    int k = 4;
    cout << kthGrammar(n, k) << endl;
}