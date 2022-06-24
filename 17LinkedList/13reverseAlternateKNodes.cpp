// Problem Link -https://www.interviewbit.com/problems/reverse-alternate-k-nodes/
#include <iostream>
using namespace std;
class listnode
{
public:
    int val;
    listnode *next;
    listnode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
listnode *solveQuestion(listnode *A, int B, int flag)
{
    if (A == NULL)
    {
        return A;
    }
    int tempB = B;
    if (flag & 1)
    {
        listnode *prev = NULL;
        listnode *curr = A;
        while (tempB-- && A != NULL)
        {
            listnode *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        A->next = solveQuestion(curr, B, flag + 1);
        return prev;
    }
    listnode *temp = A;
    while (tempB > 1 && temp != NULL)
    {
        temp = temp->next;
        tempB--;
    }
    temp->next = solveQuestion(temp->next, B, flag + 1);
    return A;
}
listnode *solve(listnode *A, int B)
{
    return solveQuestion(A, B, 1);
}
