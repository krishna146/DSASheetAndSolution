// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
private:
    void findNextGreaterElement(vector<int> &ans)
    {
        stack<int> st;
        st.push(0);
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            int item = ans[i];
            while (st.top() != 0 && st.top() <= item)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(item);
        }
    }

public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> ans;
        while (head != NULL)
        {
            ans.push_back(head->val);
            head = head->next;
        }
        findNextGreaterElement(ans);
        return ans;
    }
};
int main()
{
}