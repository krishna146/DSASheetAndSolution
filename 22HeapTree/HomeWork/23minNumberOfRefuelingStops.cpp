// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int n = stations.size();
        priority_queue<int> maxHeap;
        int distance = 0;
        int count = 0;
        int currPosition = 0;
        int currFuel = 0;
        maxHeap.push(startFuel);
        for (int i = 0; i <= n; i++)
        {
            if (i == n)
            {
                // distance between target and currPosition
                distance = target - currPosition;
            }
            else
            {
                // distance between next Station and currPosition
                distance = stations[i][0] - currPosition;
            }
            while (!maxHeap.empty() && currFuel < distance)
            {
                count++;
                currFuel += maxHeap.top();
                maxHeap.pop();
            }
            if (currFuel < distance)
                return -1;
            // updating currPosition
            currPosition += distance;
            // updating currPosition
            currFuel -= distance;
            if (i != n)
                maxHeap.push(stations[i][1]);
        }
        return count - 1;
    }
};