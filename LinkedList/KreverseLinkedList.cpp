//Problem Link:- https://www.interviewbit.com/problems/k-reverse-linked-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head, int k) {
    deque<ListNode*> pq;
    ListNode* curr = head;
    ListNode* start = new ListNode(-1);
    ListNode* dummy = start;
    while (curr != NULL){
        for(int i=0;i<k;i++){
            pq.push_back(curr);
            curr = curr->next;
            if (curr == NULL){
                break;
            }
        }
        if (pq.size() == k){
            while (!pq.empty()){
                start->next = pq.back();
                start = start->next;
                pq.pop_back();
            }
        }
        else{
            while (!pq.empty()){
                start->next = pq.front();
                start = start->next;
                pq.pop_front();
            }
        }
    }
    start->next = NULL;
    return dummy->next;
}
