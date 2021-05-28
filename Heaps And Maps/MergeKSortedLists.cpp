//Problem Link:- https://www.interviewbit.com/problems/merge-k-sorted-lists/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode* mergeKLists(vector<ListNode*> &lists){
    ListNode* result = new ListNode(-1);
    ListNode* ans = result;
    if (lists.size() == 0){
        return result->next;
    }
    priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
    for(auto x : lists){
        if (x != NULL){
            pq.push({x->val,x});
        }
    }
    while (!pq.empty()){
        auto node = pq.top();
        pq.pop();
        int data = node.first;
        ListNode* temp = node.second;
        result->next = new ListNode(data);
        if (temp->next != NULL){
            pq.push({temp->next->val,temp->next});
        }
        result = result->next;
    }
    return ans->next;
    
}
