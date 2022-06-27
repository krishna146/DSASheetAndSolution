// Problem Link -
/* By Krishna Kumar */
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
void countMaxUniqueSplit(string &s, unordered_map<string, bool> &ump, int index, int &count){
    if(index == s.size()){
        if(ump.size() > count){
            count = ump.size();
        }
    }
    for(int i = 1 ; i <= s.size() - index ; i++){
        string subStr = s.substr(index, i);
        if(ump.find(subStr) == ump.end()){
            ump.insert({subStr, 0});
            countMaxUniqueSplit(s, ump, index + i, count);
            ump.erase(subStr);   
        }
    }
}
int main()
{
    string s = "aba";
    unordered_map<string, bool> ump;
    int count = 1;
    countMaxUniqueSplit(s, ump, 0, count);
    cout << count;
}