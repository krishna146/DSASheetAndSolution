//Problem Link - //Problem Link - https://leetcode.com/problems/generate-parentheses/
/* By Krishna Kumar */
#include<iostream>
#include<string>
using namespace std;
//less parameter
void generateParanthes(int &ob, int &cb, string &str){
    if(ob == 0 && cb == 0){
        cout << str << " ";
        return;
    }
    if(ob > cb){
        return;
    }
    if(ob > 0){
        str.push_back('(');
        ob--;
        generateParanthes(ob, cb, str);
        str.pop_back();
        ob++;
    }
    if(cb > 0){
        str.push_back(')');
        cb--;
        generateParanthes(ob, cb , str);
        str.pop_back();
        cb++;
    }

}
int main(){
    string str = "(";
    int n = 3;
    int ob = 2;
    int cb = 3;
    generateParanthes(ob, cb, str);
}