// Problem Link - https://leetcode.com/problems/combination-sum-ii/
/* By Krishna Kumar */
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
void storeCombinationSum(vector<int> &candidates, int target, int index, vector<vector<int>> &ans, vector<int> &temp)
{
    if (target == 0)
    {
        ans.push_back(temp);
    }
    if (target < 0 || index == candidates.size())
    {
        return;
    }
    for (int i = index; i < candidates.size(); i++)
    {
        if (candidates[i] > target)
            break;
        if (i > index && candidates[i] == candidates[i - 1])
            continue;
        temp.push_back(candidates[i]);
        storeCombinationSum(candidates, target - candidates[i], i + 1, ans, temp);
        temp.pop_back();
    }
}
int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8 ;
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    storeCombinationSum(candidates, target, 0, ans, temp);
    for (auto row : ans)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}