// Problem Link - https://leetcode.com/problems/decode-string/
/* By Krishna Kumar */
#include <iostream>
#include <string>
using namespace std;
string decodeString(string &str, int &index)
{
    string fString;
    while(index < str.length() && str[index] != ']'){
        if(str[index] >= 'a' && str[index] <= 'z'){
            fString.push_back(str[index]);
            index++;
        }
        else{
            string digits ;
            while (str[index] >= '0' && str[index] <= '9')
            {
                digits.push_back(str[index]);
                index++;
            }
            index++;
            string temp = decodeString(str, index);
            index++;
            int count = stoi(digits);
            while(count--){
                fString += temp;
            }
            
        }
    }
    return fString;
   
}

int main()
{
    string s = "3[a]4[c]";
    int index = 0;
    cout << decodeString(s, index);
}