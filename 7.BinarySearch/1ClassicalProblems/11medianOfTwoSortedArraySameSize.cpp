// Problem Link -
/* By Krishna Kumar */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
float findMedian(vector<int> &arr1, int l1, int r1, vector<int> &arr2, int l2, int r2)
{
    if (r1 - l1 + 1 == 2)
    {
        vector<int> fans;
        fans.push_back(arr1[l1]);
        fans.push_back(arr1[l1 + 1]);
        fans.push_back(arr2[l2]);
        fans.push_back(arr2[l2 + 1]);
        sort(fans.begin(), fans.end());
        float median = (fans[1] + fans[2]) / 2;
        return median;
    }
    int mid1 = l1 + (r1 - l1) / 2;
    int mid2 = l2 + (r2 - l2) / 2;

    int size = r1 - l1 + 1;
    if (size & 1)
    {
        if (arr1[mid1] == arr2[mid2])
            return arr1[mid1];

        if (arr1[mid1] > arr2[mid2])
        {
            return findMedian(arr1, l1, mid1, arr2, mid2, r2);
        }
        return findMedian(arr1, mid1, r1, arr2, l2, mid2);
    }
    float median1 = (arr1[mid1] + arr1[mid1 + 1]) / 2;
    float median2 = (arr2[mid2] + arr2[mid2 + 1]) / 2;
    if (median1 == median2)
        return median1;
    if (median1 > median2)
    {
        return findMedian(arr1, l1, mid1 + 1, arr2, mid2, r2);
    }
    return findMedian(arr1, mid1, r1, arr2, l2, mid2 + 1);
}
int main()
{
    vector<int> arr1 ={ 1, 12, 15, 26, 38 };
    vector<int> arr2 = { 2, 13, 17, 30, 45 };
    cout << findMedian(arr1, 0, 4, arr2, 0, 4);
}
