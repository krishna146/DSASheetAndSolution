//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printKeyboard(vector<string> &input, int index, string output){
    if(index == input.size()){
        cout << output << " ";
        return;
    }
    string str = input[index];
    for(int i = 0 ; i < str.size() ; i++){
        printKeyboard(input, index + 1, output + str[i]);
    }
}
int main(){
    vector<string> input ={"abc", "def", "ghi"};
    printKeyboard(input, 0, "");
    cout << endl;
}