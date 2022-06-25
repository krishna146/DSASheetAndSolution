#include <iostream>
#include <unordered_map>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{

    // approach 1
    unordered_map<ListNode *, bool> visited;
    while (head != NULL)
    {
        if (visited[head] == true)
            return true;
        visited[head] = true;
        head = head->next;
    }
    return false;
}
