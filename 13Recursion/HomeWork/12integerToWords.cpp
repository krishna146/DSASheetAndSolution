// Problem Link -
/* By Krishna Kumar */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
private:
    vector<string> singleDigits = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> doubleDigistOne = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> doubleDigits = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    void solve(int num, string &ans, int count)
    {
        if(num == 0) return;
        int currDigit = num % 10;
        num = num / 10;
        solve(num, ans, count + 1);
        if (count == 1)
        {
            int prevDigit = num % 10;
            if (prevDigit == 1)
            {
                ans = ans + " " + doubleDigistOne[currDigit];
            }
            else
            {
                if(currDigit != 0)
                    ans = ans + " " + singleDigits[currDigit];
            }
            return;
        }
        else if (count == 2)
        {
            if (currDigit != 0 && currDigit != 1)
            {
                ans = ans + " " + doubleDigits[currDigit];
                return;
            }
        }
        else if(count == 3){
            if(currDigit != 0){
                ans = ans + " " + singleDigits[currDigit] + " Hundred";
            }
            return;
        }
        else if(count == 4){
            int prevDigit = num % 10;
            int secondPrevDigit = (num / 10) % 10;
            if(prevDigit == 1){
                ans = ans + " " + doubleDigistOne[currDigit] ; 
            }
            else{
                if(currDigit != 0)
                    ans = ans + " " + singleDigits[currDigit] ;
            }
            if(currDigit != 0 || prevDigit != 0 || secondPrevDigit != 0){
                ans = ans + " Thousand";
            }
            return;
        
        }
        else if(count == 5){
            if(currDigit != 1 && currDigit != 0){
                ans = ans + " " + doubleDigits[currDigit] ;
                return;
            }
            return;
        }
        else if(count == 6){
            if(currDigit != 0){
                ans = ans + " " + singleDigits[currDigit] + " Hundred";
            }
        }
        else if(count == 7){
            int prevDigit = num % 10;
            int secondPrevDigit = (num / 10) % 10;
            if(prevDigit == 1){
                ans = ans + " " + doubleDigistOne[currDigit]; 
            }
            else{
                ans = ans + " " + singleDigits[currDigit] ;
            }
            if(currDigit != 0 || prevDigit != 0 || secondPrevDigit != 0){
                ans = ans + " Million";
            }
            return;
        
        }
        else if(count == 8){
            if(currDigit != 1 && currDigit != 0){
                ans = ans + + " " + doubleDigits[currDigit] ;
                return;
            }
            return;
        }
        else if(count == 9){
            if(currDigit != 0){
                ans = ans + " " + singleDigits[currDigit]  + " Hundred";
            }
        }
        else{
            if(currDigit != 0){
                ans = ans + singleDigits[currDigit]  + " Billion";
            }
        }

    }

public:
    string numberToWords(int num)
    {
        if(num == 0) return "Zero";
        string ans;
        solve(num, ans, 1);
        if(ans[0] == ' ')
            ans.erase(0, 1);
        return ans;
    }
};
int main()
{
    int num;
    cin >> num;
    Solution obj;
    cout << obj.numberToWords(num);
}