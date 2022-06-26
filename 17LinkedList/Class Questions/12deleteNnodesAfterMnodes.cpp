// Problem Link -https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1/#
/* By Krishna Kumar */
#include <iostream>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void linkdelete(struct Node *head, int M, int N)
{
    while (head != NULL)
    {
        int tempM = M;
        while (tempM > 1 && head != NULL)
        {
            head = head->next;
            tempM--;
        }
        int tempN = N;
        while (tempN-- && head != NULL && head->next != NULL)
        {
            head->next = head->next->next;
        }
        if (head != NULL)
            head = head->next;
    }
}