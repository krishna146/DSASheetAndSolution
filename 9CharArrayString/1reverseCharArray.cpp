//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<string.h>
using namespace std;
void reverse(char name[], int size){
    int l = 0;
    int r = size - 1;
    while(l < r){
        swap(name[l], name[r]);
        l++;
        r--;
    }
}
int main(){
    char name[10];
    cin >> name;
    reverse(name, strlen(name));
    cout << name;
}