// Problem Link -
/* By Krishna Kumar */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print2DArray(vector<vector<pair<int, int>>> &vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j].first << " ";
        }
        cout << endl;
    }
}
class Solution
{
private:
    void solve(vector<int> &jobs, int remJob, int remWorkers, int &ans, int currMaxTime, unordered_map<int, bool> &visited)
    {
        if (remWorkers == 0)
        {
            ans = min(currMaxTime, ans);
            return;
        }
        vector<vector<pair<int, int>>> possibleAssignedJob;
        vector<pair<int, int>> temp;
        int index = 0;
        int k = remJob - remWorkers + 1;
        if (remWorkers != 1)
            findLessThanKLengthSubset(jobs, possibleAssignedJob, index, temp, k, visited);
        else
        {
            findKLengthSubset(jobs, possibleAssignedJob, index, temp, k, visited);
        }
        cout << possibleAssignedJob.size() << " ";
        for (auto jobArray : possibleAssignedJob)
        {
            int sum = 0;
            for (auto el : jobArray)
            {
                visited[el.second] = true;
                sum += el.first;
            }
            int temp = currMaxTime;
            currMaxTime = max(sum, currMaxTime);
            solve(jobs, remJob - jobArray.size(), remWorkers - 1, ans, currMaxTime, visited);
            currMaxTime = temp;
            for (auto el : jobArray)
            {
                visited[el.second] = false;
            }
        }
    }

private:
    void findLessThanKLengthSubset(vector<int> &arr, vector<vector<pair<int, int>>> &ans, int index, vector<pair<int, int>> &temp, int &k, unordered_map<int, bool> &visited)
    {
        if (index == arr.size())
        {
            if (temp.size() > 0 && temp.size() <= k)
            {
                ans.push_back(temp);
            }
            return;
        }

        findLessThanKLengthSubset(arr, ans, index + 1, temp, k, visited);
        if (!visited[index])
        {
            pair<int, int> curr;
            curr.first = arr[index];
            curr.second = index;
            temp.push_back(curr);
            findLessThanKLengthSubset(arr, ans, index + 1, temp, k, visited);
            temp.pop_back();
        }
    }

private:
    void findKLengthSubset(vector<int> &arr, vector<vector<pair<int, int>>> &ans, int index, vector<pair<int, int>> &temp, int &k, unordered_map<int, bool> &visited)
    {
        if (index == arr.size())
        {
            if (temp.size() == k)
            {
                ans.push_back(temp);
            }
            return;
        }

        findKLengthSubset(arr, ans, index + 1, temp, k, visited);
        if (!visited[index])
        {
            pair<int, int> curr;
            curr.first = arr[index];
            curr.second = index;
            temp.push_back(curr);
            findKLengthSubset(arr, ans, index + 1, temp, k, visited);
            temp.pop_back();
        }
    }

public:
    int minimumTimeRequired(vector<int> &jobs, int k)
    {
        int remJob = jobs.size();
        int currMaxTime = INT_MIN;
        int ans = INT_MAX;
        unordered_map<int, bool> visited;
        solve(jobs, remJob, k, ans, currMaxTime, visited);
        return ans;
    }
};
int main()
{
    vector<int> jobs = {9899456, 8291115, 9477657, 9288480, 5146275, 7697968, 8573153, 3582365, 3758448, 9881935, 2420271, 4542202};
    int k = 9;
    Solution obj;
    cout << obj.minimumTimeRequired(jobs, k);
}