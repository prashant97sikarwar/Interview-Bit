//Problem Link:- https://www.interviewbit.com/problems/kth-node-from-middle/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int solve(ListNode* head, int k) {
    
    //468->335
    int size = 0;
    ListNode* curr = head;
    while (curr != NULL){
        size++;
        curr = curr->next;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    int mid_idx = (size / 2) + 1;
    if (k >= mid_idx){
        return -1;
    }
    if (size == 2){
        return slow->val;
    }
    int pt = mid_idx-k;
    int cnt = 1;
    while (cnt != pt){
        cnt++;
        slow = slow->next;
    }
    return slow->val;
}
