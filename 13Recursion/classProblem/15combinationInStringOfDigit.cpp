//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<string>
using namespace std;

void findCombinations(string input, int i , string output){

    if(input[i] == '\0')
    {
        cout << output << endl;
        return;
    }
    findCombinations(input, i + 1, output + input[i]);
    if(!(input[i + 1] == '\0'))
        findCombinations(input, i + 1, output + input[i] + " " );
}
int main(){
    string input = "123";
    findCombinations(input, 0, "");
}