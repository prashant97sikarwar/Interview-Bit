//Problem Link:- https://www.interviewbit.com/problems/sort-binary-linked-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* solve(ListNode* head) {
    if (head == NULL || head->next == NULL){
        return head;
    }
    ListNode* zero = new ListNode(-1);
    ListNode* zerod = zero;
    ListNode* one = new ListNode(-1);
    ListNode* oned = one;
    ListNode* curr = head;
    while (curr != NULL){
        if (curr->val == 1){
            one->next = curr;
            one = one->next;
        }
        else{
            zero->next = curr;
            zero = zero->next;
        }
        curr = curr->next;
    }
    if (oned->next != NULL){
        zero->next = oned->next;
    }
    one->next = NULL;
    return zerod->next;
}
