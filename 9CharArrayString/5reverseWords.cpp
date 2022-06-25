//Problem Link - https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1/
/* By Krishna Kumar */
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
string reverseWords(string s) 
{ 
    reverse(s.begin(), s.end());
    int i = 0;
    int begin = 0;
    cout << s << endl;
    while(i < s.size()){
        begin = i;
        while(s[i] != '.' && s[i] != '\0'){
            // char ch = s[i] ;
            // bool check = (ch == '.');
            // cout << check << endl;
            i++;
        }
        reverse(s.begin() + begin , s.begin() + i);
        i++;
        
    }
    return s;
} 
int main(){
    string str = "My.Name.is.Babbar";
    // reverse(str.begin(), str.end());
    // int i = 0;
    // while(i < str.size()){
    //     string temp ;
    //     while (str[i] != ' ' & str[i] != '\0')
    //     {
    //         temp.push_back(str[i]);
    //         i++;
    //     }
    //     reverse(temp.begin(), temp.end());
    //     cout << temp << " " ;
    //     i++;

    // }
    cout << reverseWords(str);

}