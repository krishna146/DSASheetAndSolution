#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string solve(int N, vector<int> &A)
    {
        // code here
        string yes = "YES";
        string no = "NO";
        int first = A[0];
        int second = A[1];
        if (first == -1 * second)
        {
            for (int i = 2; i < A.size(); i++)
            {
                if (i & 1 == 0 && A[i] != first)
                {
                    return no;
                }
                if (i & 1 && A[i] != second)
                {
                    return no;
                }
            }
            return yes;
        }
        return no;
    }
};
int main()
{
    vector<int> ans;
    ans.push_back(2);   
}
