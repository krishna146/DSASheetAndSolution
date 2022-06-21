// Problem Link - https://www.geeksforgeeks.org/alphanumeric-abbreviations-of-a-string/
/* By Krishna Kumar */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void storeAbbreviation(string str, int index, vector<string> &ans, string output)
{
    if (str[index] == '\0')
    {
        ans.push_back(output);
        return;
    }
    storeAbbreviation(str, index + 1, ans, output + str[index]);
    if (output.size() >=1  && output[output.size() - 1] >= '1' && output[output.size() - 1] <= '9')
    {
        char ch = output[output.size() - 1];
        output.pop_back();
        output.push_back(ch + 1);
        storeAbbreviation(str, index + 1, ans, output);
    }
    else
    {
        storeAbbreviation(str, index + 1, ans, output + "1");
    }
}
int main()
{
    string str = "ANKS";
    int index = 0;
    vector<string> ans;
    string output;
    storeAbbreviation(str, index, ans, output);
    for (auto str : ans)
    {
        cout << str << " ";
    }
}