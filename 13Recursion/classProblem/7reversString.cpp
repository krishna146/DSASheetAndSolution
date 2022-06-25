//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<string>
using namespace std;
void reverseStrUsingSinglePointer(string &str,int start){
    if(start >= str.size()/  2)
    {
        return;
    }
    swap(str[start], str[str.size() - start - 1]);
    reverseStrUsingSinglePointer(str, start + 1);

}
void reverseStr(string &str,int start,  int end){
    if(start >= end) return;
    swap(str[start], str[end]);
    reverseStr(str, start + 1 , end - 1);

}
int main(){
    string str = "abcdefgh";
    reverseStrUsingSinglePointer(str, 0);
    cout << str << endl;
}