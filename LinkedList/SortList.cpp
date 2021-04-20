//Problem Link:- https://www.interviewbit.com/problems/sort-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* NodeMid(ListNode* head, ListNode* tail){
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != tail && fast->next != tail){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
} 

ListNode* merge(ListNode* l1, ListNode* l2){
    ListNode* head = NULL;
    if (l1->val <= l2->val){
        head = l1;
        l1->next;
    }
    else{
        head = l2;
        l2 = l2->next;
    }
    ListNode* res = head;
    while (l1 != NULL && l2 != NULL){
        if (l1->val <= l2->val){
            head->next = l1;
            l1 = l1->next;
        }
        else{
            head->next = l2;
            l2 = l2->next;
        }
        head = head->next;
    }
    if (l1 != NULL){
        head->next = l1;
    }
    if (l2 != NULL){
        head->next = l2;
    }
    return res;
}

ListNode* MergeSort(ListNode* head, ListNode* tail){
    if (head == tail){
        ListNode* br = new ListNode(head->val);
        return br;
    }
    ListNode* mid = NodeMid(head,tail);
    ListNode* first = MergeSort(head,mid);
    ListNode* sec = MergeSort(mid->next,tail);
    return merge(first,sec);
}
ListNode* Solution::sortList(ListNode* head) {
    if (head == NULL || head->next == NULL){
        return head;
    }
    ListNode* tail = head;
    while (tail->next != NULL){
        tail = tail->next;
    }
    return MergeSort(head,tail);
}
