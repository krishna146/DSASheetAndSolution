//problem -> https://leetcode.com/problems/copy-list-with-random-pointer/
#include<unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        Node *tempTail = head;
        unordered_map<Node*, Node*> mapping;
        Node *dummy = new Node(-1);
        Node *tail = dummy;

    while(tempTail != NULL){
        Node *temp = new Node(tempTail -> val);
        mapping[tempTail] = temp;
        tail -> next = temp;
        tail = temp;
        tempTail = tempTail -> next;
    }
    tempTail = head;
    tail = dummy -> next;
    while(tempTail != NULL){
        if(tempTail -> random == NULL){
            tail -> random = NULL;
        }
        else{
            tail -> random = mapping[tempTail->random];
        }
        tail = tail -> next;
        tempTail = tempTail -> next;
    }
           
    return dummy -> next;
        
    }
};