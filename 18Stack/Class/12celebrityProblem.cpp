// Problem Link - https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    bool knows(vector<vector<int>> &M, int row, int col)
    {
        return M[row][col];
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // code here
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }
        while (st.size() > 1)
        {
            int firstPerson = st.top();
            st.pop();
            int secondPerson = st.top();
            st.pop();
            if (knows(M, firstPerson, secondPerson))
            {
                st.push(secondPerson);
            }
            else
            {
                st.push(firstPerson);
            }
        }
        int potentialSoln = st.top();
        st.pop();
        // checkPoint1
        for (int col = 0; col < n; col++)
        {
            if (M[potentialSoln][col] == 1)
                return -1;
        }
        // checkPoint 2
        for (int row = 0; row < n; row++)
        {
            if (row != potentialSoln && M[row][potentialSoln] == 0)
            {
                return -1;
            }
        }
        return potentialSoln;
    }
};
int main()
{
}