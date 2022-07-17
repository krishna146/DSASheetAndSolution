// Problem Link -https://practice.geeksforgeeks.org/problems/circular-tour/1#
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};
class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        // Your code here
        for (int i = 0; i < n; i++)
        {
            int index = i;
            bool flag = true;
            int pet = p[index].petrol;
            int dist = p[index].distance;
            int temp = n;
            while (temp--)
            {
                if (pet < dist)
                {
                    flag = false;
                    break;
                }
                else
                {
                    index = (index + 1) % n;
                    pet = pet - dist + p[index].petrol;
                    dist = p[index].distance;
                }
            }
            if (flag)
                return index;
        }
        return -1;
    }
};
int main()
{
}