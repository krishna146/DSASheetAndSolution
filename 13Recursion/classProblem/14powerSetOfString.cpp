//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<string>
using namespace std;
void printPowerSetOfString(string str, int i, string op){
    if(str[i] == '\0')
    {
        cout << op << endl;
        return;
    }
    //exclude
    printPowerSetOfString(str, i + 1, op);
    //include
    printPowerSetOfString(str, i + 1, op + str[i]);

}
int main(){
    string str = "abc";
    printPowerSetOfString(str, 0, "");
}