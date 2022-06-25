//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int main(){
    
    int i = 5;
    //reference variable
    int &j = i;
    cout << i << endl;
    i++;
    cout << j << endl;
    j++;
    cout << i << endl;  

}