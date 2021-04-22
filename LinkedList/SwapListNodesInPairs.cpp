//Problem Link:- https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == NULL && head->next == NULL){
        return head;
    }
    ListNode* curr = head;
    ListNode* temp = NULL;
    while (curr != NULL && curr->next != NULL){
        temp = curr->next;
        int ptr = curr->val;
        curr->val = temp->val;
        temp->val = ptr;
        curr = temp->next;
    }
    return head;
}
