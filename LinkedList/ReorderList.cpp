//Problem Link:- https://www.interviewbit.com/problems/reorder-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reorderList(ListNode* head) {
    if (head == NULL && head->next == NULL){
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* first = head;
    ListNode* curr = slow->next;
    ListNode* prev = NULL;
    ListNode* nxt;
    while (curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    ListNode* sec = prev;
    slow->next = NULL;
    while (sec != NULL){
        nxt = first->next;
        first->next = sec;
        first = sec;
        sec = nxt;
    }
    return head;
}
