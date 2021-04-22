//Problem link:- https://www.interviewbit.com/problems/add-two-numbers-as-lists/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* result = new ListNode(-1);
    ListNode* ans = result;
    while (l1 != NULL && l2 != NULL){
        int data = l1->val + l2->val + carry;
        carry = data / 10;
        data %= 10;
        result->next = new ListNode(data);
        result = result->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL){
        int data = l1->val + carry;
        carry = data / 10;
        data %= 10;
        result->next = new ListNode(data);
        result = result->next;
        l1 = l1->next;
    }
    while (l2 != NULL){
        int data = l2->val + carry;
        carry = data / 10;
        data %= 10;
        result->next = new ListNode(data);
        result = result->next;
        l2 = l2->next;
    }
    if (carry > 0){
        result->next = new ListNode(carry);
    }
    return ans->next;
}
