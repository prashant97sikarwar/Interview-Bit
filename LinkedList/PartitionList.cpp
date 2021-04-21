//Problem Link:- https://www.interviewbit.com/problems/partition-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int k) {
    ListNode* curr = head;
    if (head == NULL && head->next == NULL){
        return head;
    }
    bool flag = false;
    ListNode* res;
    if (head->val >= k){
        curr = new ListNode(-1);
        res = curr;
        flag = true;
        curr->next = head;
    }
    else{
        while (curr != NULL && curr->next != NULL && curr->next->val < k){
            curr = curr->next;
        }
    }
    
    ListNode* key = head;
    ListNode* tail = curr->next;
    key = tail;
    while (key != NULL && key->next != NULL){
        if (key->next->val < k){
            curr->next = key->next;
            key->next = key->next->next;
            curr = curr->next;
        }
        else{
            key = key->next;
        }
    }
    curr->next = tail;
    if (flag == false)
        return head;
    else{
        return res->next;
    }
}
