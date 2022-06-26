//problem link -> https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1/#
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    // Your code here
    Node *forward = head;
    while (forward != NULL && n--)
    {
        forward = forward->next;
    }
    Node *start = head;
    while (forward != NULL)
    {
        forward = forward->next;
        start = start->next;
    }
    if (n > 0)
        return -1;
    return start->data;
}