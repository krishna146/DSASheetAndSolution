// Problem Link -
/* By Krishna Kumar */
#include <iostream>
#include <vector>
using namespace std;
void storePermutation(vector<int> &nums, int index, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[i], nums[index]);
        storePermutation(nums, index + 1, ans);
        swap(nums[i], nums[index]);
    }
}
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    storePermutation(nums, 0, ans);
    for (auto row : ans)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}