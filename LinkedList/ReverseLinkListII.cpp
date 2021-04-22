//Problem Link:- https://www.interviewbit.com/problems/reverse-link-list-ii/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == NULL || head->next == NULL){
        return head;
    }
    ListNode* curr =  head;
    ListNode* prev = NULL;
    ListNode* nxt;
    int cnt = 1;
    while (curr != NULL && cnt != m){
        cnt++;
        prev = curr;
        curr = curr->next;
    }
    ListNode* temp = prev;
    ListNode* temp2 = curr;
    while (curr != NULL && cnt != n+1){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        cnt++;
    }
    if (temp != NULL){
        temp->next = prev;   
    }
    else{
        head = prev;
    }
    temp2->next = curr;
    return head;
    
}
