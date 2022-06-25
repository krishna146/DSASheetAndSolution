//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5};
    int *p = arr;
    cout << p << endl;
    cout << *p << endl;

    char ch[] = "abcd";
    char *ptr = ch;
    cout << ptr << endl;
    cout << *ptr << endl;


    char ph = 'a';
    char *ptrph = &ph;
    cout << ptrph << endl;
}