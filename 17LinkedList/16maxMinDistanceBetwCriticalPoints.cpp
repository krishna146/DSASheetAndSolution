// Problem Link -https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
/* By Krishna Kumar */
#include <iostream>
#include <unordered_map>
#include<algorithm>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    int totalCp = 0;
    int index = 1;
    int firstCp = INT_MAX;
    int lastCp = INT_MIN;
    int prevCp = -1;
    int minDistance = INT_MAX;
    bool flag = false;
    while (head->next->next != NULL)
    {
        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *forward = curr->next;
        if (curr->val > prev->val && curr->val > forward->val)
        {
            flag = true;
        }
        if (curr->val < prev->val && curr->val < forward->val)
        {
            flag = true;
        }
        if (flag)
        {
            totalCp++;
            firstCp = min(index, firstCp);
            if (prevCp != -1)
                minDistance = min(minDistance, index - prevCp);
            prevCp = index;
            lastCp = max(index, lastCp);
            flag = false;
        }
        index++;
        head = head->next;
    }
    cout << totalCp << endl;
    vector<int> ans;
    if (totalCp >= 2)
    {
        ans.push_back(minDistance);
        ans.push_back(lastCp - firstCp);
    }
    else
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    return ans;
}