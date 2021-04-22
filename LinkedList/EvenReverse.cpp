//Problem Link:- https://www.interviewbit.com/problems/even-reverse/

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
    ListNode* curr = head;
    ListNode* even = head->next;
    ListNode* evend = even;
    ListNode* odd = curr;
    ListNode* first = odd;
    curr = curr->next->next;
    int cnt = 2;
    while (curr != NULL){
        cnt++;
        if (cnt % 2 == 0){
            even->next = curr;
            even = even->next;
        }
        else{
            odd->next = curr;
            odd = odd->next;
        }
        curr = curr->next;
    }
    odd->next = NULL;
    even->next = NULL;
    curr = evend;
    ListNode* prev = NULL;
    ListNode* nxt;
    while (curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    ListNode* sec = prev;
    while (sec != NULL){
        nxt = first->next;
        first->next = sec;
        first = sec;
        sec = nxt;
    }
    return head;
}
