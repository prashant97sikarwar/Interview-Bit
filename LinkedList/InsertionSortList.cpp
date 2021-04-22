//Problem Link:- https://www.interviewbit.com/problems/insertion-sort-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
    if (head == NULL || head->next == NULL){
        return head;
    }
    ListNode* curr = head;
    while (curr != NULL){
        ListNode* nxt = curr->next;
        ListNode* start = head;
        ListNode* prev = head;
        while (start != nxt){
            if (start->val > curr->val){
                curr->next = start;
                if (start == head){
                    head = curr;
                }
                else{
                    prev->next = curr;
                }
                while (start->next != curr){
                    start = start->next;
                }
                start->next = nxt;
            }
            prev = start;
            start = start->next;
        }
        curr = nxt;
    }
    return head;
}