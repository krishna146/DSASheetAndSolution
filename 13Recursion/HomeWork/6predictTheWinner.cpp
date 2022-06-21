// Problem Link - https://leetcode.com/problems/predict-the-winner/
/* By Krishna Kumar */
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
long long int calcPlayer1Score(vector<int> &nums, int left, int right)
{
    if (left > right)
    {
        return 0;
    }
    int score1 = nums[left] + min(calcPlayer1Score(nums, left + 1, right - 1), calcPlayer1Score(nums, left + 2, right));
    int score2 = nums[right] + min(calcPlayer1Score(nums, left + 1, right - 1), calcPlayer1Score(nums, left, right - 2));
    return max(score1, score2);
}
int main()
{
    vector<int> nums = {1, 5, 233, 7};
    long long int player1Score = calcPlayer1Score(nums, 0, nums.size() - 1);
    long long int sum = 0;
    for (auto el : nums)
    {
        sum += el;
    }
    long long int player2Score = sum - player1Score;
    cout << (player1Score >= player2Score);
}