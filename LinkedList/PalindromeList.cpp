//Problem Link:- https://www.interviewbit.com/problems/palindrome-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* nxt;
    ListNode* curr = head;
    while( curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

int lPalin(ListNode* head) {
    if (head == NULL){
        return 1; 
    }
    if (head->next == NULL){
        return 1;
    }
    if (head->next->next == NULL){
        if (head->val == head->next->val){
            return 1;
        }
        else{
            return 0;
        }
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != NULL && fast->next->next == NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* temp = reverse(slow->next);
    while (head != NULL && temp != NULL){
        if (head->val != temp->val){
            return 0;
        }
        head = head->next;
        temp = temp->next;
    }
    return 1;
}
