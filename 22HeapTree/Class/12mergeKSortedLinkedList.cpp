// Problem Link 1 - https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
// Problem Link 2 - https://leetcode.com/problems/merge-k-sorted-lists/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Cmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
class Solution
{
public:
    // Function to merge K sorted linked list.
    Node *mergeKLists(Node *arr[], int K)
    {
        priority_queue<Node *, vector<Node *>, Cmp> minHeap;
        Node *dummy = new Node(-1);
        Node *tail = dummy;
        for (int i = 0; i < K; i++)
        {
            if (arr[i])
            {
                minHeap.push(arr[i]);
            }
        }
        while (!minHeap.empty())
        {
            Node *temp = minHeap.top();
            minHeap.pop();
            tail->next = temp;
            tail = temp;
            if (temp->next)
            {
                minHeap.push(temp->next);
            }
        }
        return dummy->next;
    }
};