// Problem Link -
/* By Krishna Kumar */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printKeyboard(vector<string> &input, int index, string output, vector<string> &ans)
{
    if (index == input.size())
    {
        ans.push_back(output);
        return;
    }
    string str = input[index];
    for (int i = 0; i < str.size(); i++)
    {
        printKeyboard(input, index + 1, output + str[i], ans);
    }
}
void print(vector<string> &ans){
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
}
int main()
{
    string digits;
    cin >> digits;
    vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> input;
    vector<string> ans;
    if (digits.size() == 0)
    {
        print(ans);
        return 0;
    }
    for (int i = 0; i < digits.size(); i++)
    {
        input.push_back(map[digits[i] - '0' - 2]);
    }
    printKeyboard(input, 0, "", ans);
    print(ans);
}