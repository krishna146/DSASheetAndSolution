// Problem Link -https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
/* By Krishna Kumar */
#include <iostream>
#include<unordered_map>
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
Node *removeDuplicates(Node *head)
{
    // your code goes here
    unordered_map<int, bool> visited;
    Node *temp = head;
    visited[temp->data] = 1;
    while (temp != NULL && temp->next != NULL)
    {
        if (visited[temp->next->data])
        {
            temp->next = temp->next->next;
        }
        else
        {
            visited[temp->next->data] = 1;
            temp = temp->next;
        }
    }
    return head;
}