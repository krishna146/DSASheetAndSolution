//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str = "Babbar";
    
    str.erase(3, 3);//(index, length)
    cout << str << endl;
    
    str.push_back('l');
    cout << str << endl;
    
    str.replace(1, 2, "kri");//(index, index, string)
    cout << str << endl;

    cout << str.substr(1, 3) << endl;//(index, index)

    cout << str.find("kr") << endl;
}