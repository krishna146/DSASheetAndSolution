// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Item
{
    int value;
    int weight;
};
class Solution
{
private:
    static bool cmp(Item a, Item b)
    {
        double ratioA = float(a.value) / a.weight;
        double ratioB = float(b.value) / b.weight;
        return ratioA > ratioB;
    }

public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double profit = 0;
        sort(arr, arr + n, cmp);
        for (int idx = 0; idx < n; idx++)
        {
            int weightAvailable = arr[idx].weight;
            if (W > weightAvailable)
            {
                W = W - weightAvailable;
                profit += arr[idx].value;
            }
            else
            {
                profit += float(arr[idx].value) / arr[idx].weight * W;
                W = 0;
                break;
            }
        }

        return profit;
    }
};