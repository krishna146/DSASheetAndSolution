// Problem Link -https://leetcode.com/problems/permutation-sequence/
/* By Krishna Kumar */
#include <iostream>
#include <string>
#include <vector>
#include<math.h>
using namespace std;
string getKthPermutation(vector<char> &nums, int &k, string &ans)
{

    if (k == 1)
    {
        for (int index = 1; index < nums.size(); index++)
        {
            ans.push_back(nums[index]);
        }
        return ans;
    }
    int fact = 1;
    for (int i = 1; i <= nums.size() - 1; i++)
    {
        fact = fact * i;
    }
    float div = fact / (nums.size() - 1);
    int position = ceil(k / div);
    ans.push_back(nums[position]);
    nums.erase(nums.begin() + position);
    if (k % (int)div == 0)
    {
        k = div;
    }
    else
    {
        k = k % (int)div;
    }

    return getKthPermutation(nums, k, ans);
}
int main()
{
    int n = 3;
    int k = 3;
    vector<char> nums(n + 1);
    for (int i = 1; i <= n; i++)
    {
        nums[i] = '0' + i;
    }
    string ans;
    getKthPermutation(nums, k, ans);
    cout << ans;
}