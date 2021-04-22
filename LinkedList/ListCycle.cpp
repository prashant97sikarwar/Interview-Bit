//Problem Link:- interviewbit.com/problems/list-cycle/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    bool flag = false;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            flag = true;
            break;
        }
    }
    if (flag == false){
        return NULL;
    }
    slow = head;
    while (slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}