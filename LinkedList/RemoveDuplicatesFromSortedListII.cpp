//Problem Link:- https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* prev = new ListNode(-1);
    ListNode* res = prev;
    prev->next = head;
    while (curr != NULL && curr->next != NULL){
        temp = curr->next;
        if (temp->val == curr->val){
            while (temp != NULL && temp->val == curr->val){
                temp = temp->next;
            }
            prev->next = temp;
            curr = temp;
        }
        else{
            prev = prev->next;
            curr = curr->next;
        }
    }
    return res->next;
}
