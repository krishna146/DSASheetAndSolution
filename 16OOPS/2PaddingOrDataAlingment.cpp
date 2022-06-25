//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
class A{
    char a;
    int b;
};
class B{
    char a;
    short int c;
    short int d;
    int b;
};
int main(){
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
}