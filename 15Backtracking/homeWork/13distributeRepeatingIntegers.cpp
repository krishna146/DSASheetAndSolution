// Problem Link -
/* By Krishna Kumar */
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
void solve(vector<int> &quantity, int index, vector<int> &numsVector, bool &ans)
{
    if (index == quantity.size())
    {
        ans = true;
        return;
    }
    for (int i = 0; i < quantity.size(); i++)
    {
        if (i > index && quantity[i] == quantity[i - 1])
            continue;
        for (int j = 0; j < numsVector.size(); j++)
        {
            if (numsVector[j] > quantity[i] && numsVector[j] != numsVector[j - 1] && j > 0)
            {
                numsVector[j] -= quantity[i];
                solve(quantity, index + 1, numsVector, ans);
                numsVector[j] += quantity[i];
                if (ans == true)
                    return;
            }
        }
        if (ans == true)
            return;
    }
}
bool canDistribute(vector<int> &nums, vector<int> &quantity)
{
    unordered_map<int, int> numsMap;
    bool ans = false;
    int index = 0;
    for (auto el : nums)
    {
        numsMap[el]++;
    }
    vector<int> numsVector;
    for (auto el : numsMap)
    {
        numsVector.push_back(el.second);
    }
    sort(numsVector.begin(), numsVector.end());
    sort(quantity.begin(), quantity.end());
    solve(quantity, index, numsVector, ans);
    return ans;
}
int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 23, 24, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 30, 31, 31, 32, 32, 33, 33, 34, 34, 35, 35, 36, 36, 37, 37, 38, 38, 39, 39, 40, 40, 41, 41, 42, 42, 43, 43, 44, 44, 45, 45, 46, 46, 47, 47, 48, 48, 49, 49, 50, 50};
    vector<int> quantity = {2, 2, 2, 2, 2, 2, 2, 2, 2, 3};
    cout << canDistribute(nums, quantity) << endl;
}