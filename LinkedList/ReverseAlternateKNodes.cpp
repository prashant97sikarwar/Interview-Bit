//Problem Link;- https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* solve(ListNode* head, int k) {
    if (head == NULL || head->next == NULL){
        return head;
    }
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* nxt;
    int cnt = 0;
    while (curr != NULL && cnt < k){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        cnt++;
    }
    if (head != NULL){
        head->next = curr;   
    }
    cnt = 0;
    while (curr != NULL && cnt < k-1){
        curr = curr->next;
        cnt++;
    }
    if (curr != NULL){
        curr->next = solve(curr->next,k);
    }
    return prev;
}