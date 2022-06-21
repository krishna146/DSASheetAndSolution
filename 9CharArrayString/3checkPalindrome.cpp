//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<string>
using namespace std;
bool checkPalindrome(string str)
{
    // Write your code here.
	string temp;
	for(int i = 0 ; i < str.size() ; i++){
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i]  >= '0' && str[i] <= '9') )
			temp.push_back(str[i]);
		else if(str[i] >= 'A' && str[i] <= 'Z')
			temp.push_back(str[i] + 32);
	}
    int left = 0;
	int right = temp.size() - 1;
	while(left < right){
		if(temp[left] != temp[right])
			return false;
		left++;
		right--;
	}
	return true;
}
int main(){
    
}
