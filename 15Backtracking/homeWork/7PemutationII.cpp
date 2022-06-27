// Problem Link -
/* By Krishna Kumar */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void storeUniquePermutation(vector<int> &nums, vector<vector<int>> &ans, int index)
{
    if (index == nums.size())
    {

        ans.push_back(nums);
    }
    unordered_map<int, bool> visited;
    for (int i = index; i < nums.size(); i++)
    {
        if (!visited[nums[i]])
        {
            visited[nums[i]] = true;
            swap(nums[i], nums[index]);
            storeUniquePermutation(nums, ans, index + 1);
            swap(nums[i], nums[index]);
        }
    }
}
int main()
{
    vector<int> nums = {2, 2, 1, 1};
    vector<vector<int>> ans;
    storeUniquePermutation(nums, ans, 0);
    for (auto row : ans)

    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}