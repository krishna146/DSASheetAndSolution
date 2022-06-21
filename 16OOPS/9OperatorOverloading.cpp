//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
class Demo{
    public:
    int first;
    int second;
    Demo operator + (Demo &temp){
        Demo result;
        result.first = this -> first + temp.first;
        result.second = this -> second + temp.second;
        return result;
    }
void operator ++(){
    cout << "Unary operator overloaded" << endl;
}
};
void operator << (ostream& os, Demo &obj){
    cout << obj.first << endl;
    cout << obj.second << endl;
}

int main(){
    Demo a;
    Demo b;
    Demo c = a + b;
    ++a;
    Demo obj;
    cout << obj;
}