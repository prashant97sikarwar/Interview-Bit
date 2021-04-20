//problem Link:- https://www.interviewbit.com/problems/merge-two-sorted-lists/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* res = NULL;
    if (l1->val <= l2->val){
        res = l1;
        l1 = l1->next;
    }
    else{
        res = l2;
        l2 = l2->next;
    }
    ListNode* result = res;
    while (l1 != NULL && l2 != NULL){
        if (l1->val <= l2->val){
            res->next = l1;
            l1 = l1->next;
        }
        else{
            res->next = l2;
            l2 = l2->next;
        }
        res = res->next;
    }
    if (l1 != NULL){
        res->next = l1;
    }
    if (l2 != NULL){
        res->next = l2;
    }
    return result;
}
