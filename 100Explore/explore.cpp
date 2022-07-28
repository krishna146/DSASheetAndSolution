#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void solve(int *arr, int &index, int N, int mini, int maxi)
    {
        if (index == N)
            return;
        if (arr[index] > mini && arr[index] < maxi)
        {
            int data = arr[index++];
            solve(arr, index, N, mini, data);
            solve(arr, index, N, data, maxi);
        }
        return;
    }

public:
    int canRepresentBST(int arr[], int N)
    {
        // code here
        int index = 0;
        solve(arr, index, N, INT_MIN, INT_MAX);
        if (index == N)
            return 1;
        return 0;
    }
};
int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    Solution obj;
    cout <<"ans" << obj.canRepresentBST(arr, n);
}
