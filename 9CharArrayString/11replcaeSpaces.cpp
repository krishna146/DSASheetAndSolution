//Problem Link - https://www.codingninjas.com/codestudio/problems/replace-spaces_1172172?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_5
/* By Krishna Kumar */
#include<iostream>
#include<string>
using namespace std;
string replaceSpaces(string &str){
	// Write your code here.
	int i = 0;
	while(i < str.size()){
		if(str[i] == ' ')
			str.replace(i, 1, "@40");
		i++;
	}
	return str;
}
int main(){
    string str = "krishna jaiswal";
    cout << replaceSpaces(str);
}