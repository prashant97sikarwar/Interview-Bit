//Problem Link:- https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* curr = head;
    ListNode* temp;
    if (head == NULL || head->next == NULL){
        return head;
    }
    while (curr != NULL && curr->next != NULL){
        temp = curr->next;
        while (temp != NULL && curr->val == temp->val){
            temp = temp->next;
        }
        curr->next = temp;
        curr = curr->next;
    }
    return head;
}