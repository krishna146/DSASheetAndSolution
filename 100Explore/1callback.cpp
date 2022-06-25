//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int A(int x){
    cout << "I am in a A function" << endl;
    return x;
    
}
int B(int x){
    cout << "I am in a B function" << endl;
    return x;

}
void C (int par, int (*p)(int x) ){
    (*p)(par);
}
int main(){
    C(100, &A);

}