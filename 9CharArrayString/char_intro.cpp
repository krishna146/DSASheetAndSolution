//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<string.h>
using namespace std;
int getLength(char arr[]){
    int i = 0;
    int count = 0;
    while(arr[i] != '\0'){
        count ++;
        i++;
    }
    return count;
}
int main(){
  /*  char name[10];
    cin >> name;
    cout << name << endl;
    char name1[10] = "kri  shna";
    cout << name1 << endl;
    cout << getLength(name) << endl;
    cout << strlen(name) << endl;//using predefined function

    */
    char a[10];
    char b[11];
    cin >> a >> b;
    cout << strcmp(a, b) << endl;;

    strcpy(a, b);//strcmp(destination, source)
    cout << a << b << endl;
}