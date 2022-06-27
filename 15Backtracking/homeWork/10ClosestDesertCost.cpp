// Problem Link -https://leetcode.com/problems/closest-dessert-cost/
/* By Krishna Kumar */
#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &toppingCosts, int tIndex, int &target, int &currCost, int &currAns)
{
    if (tIndex == toppingCosts.size())
    {
        if (abs(target - currCost) < abs(target - currAns))
        {
            currAns = currCost;
            return;
        }
        if (abs(target - currCost) == abs(target - currAns))
        {
            if (currCost < currAns)
                currAns = currCost;
            return;
        }
        return;
    }
    // topping handling
    for (int i = 0; i <= 2; i++)
    {
        currCost += toppingCosts[tIndex] * i;
        solve(toppingCosts, tIndex + 1, target, currCost, currAns);
        currCost -= toppingCosts[tIndex] * i;
    }


};
int main()
{
    vector<int> baseCosts = {1, 7};
    vector<int> toppingCosts = {3, 4};
    int target = 10;
    int currAns = INT_MAX;
    for (int i = 0; i < baseCosts.size(); i++)
    {
        int currCost = baseCosts[i];
        solve(toppingCosts, 0, target, currCost, currAns);
    }
    cout << currAns;
    
}