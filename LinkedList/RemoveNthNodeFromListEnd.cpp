//Problem Link:- https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 ListNode* DeleteNode(ListNode* head,ListNode* slow){
     if (slow == head){
         ListNode* temp = head->next;
         delete (head);
         return temp;
     }
     if (slow->next == NULL){
         ListNode* curr = head;
         while (curr->next != slow){
             curr = curr->next;
         }
         curr->next = NULL;
         return head;
     }
     ListNode* curr = head;
     while (curr->next != slow){
         curr = curr->next;
     }
     ListNode* temp = curr->next->next;
     curr->next = temp;
     delete (slow);
     return head;
 }
 
ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* curr = head;
    int cnt = 0;
    while (curr != NULL){
        cnt++;
        curr = curr->next;
    }
    if (n > cnt){
        return head->next;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    for(int i=0;i<n-1;i++){
        fast = fast->next;
    }
    while (fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    return DeleteNode(head,slow);
    
}
