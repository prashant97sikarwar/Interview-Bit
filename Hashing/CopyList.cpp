//Problem Link:- https://www.interviewbit.com/problems/copy-list/

#include<bits/stdc++.h>
using namespace std;


struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode* copyRandomList(RandomListNode* head) {
    RandomListNode* curr = head;
    unordered_map<RandomListNode*, RandomListNode*> ump;
    while (curr != NULL){
        ump[curr] = new RandomListNode(curr->label);
        curr = curr->next;
    }
    curr = head;
    while (curr != NULL){
        RandomListNode* temp = ump[curr];
        if (ump.find(curr->next) != ump.end()){
            temp->next = ump[curr->next];
        }
        if (ump.find(curr->next) == ump.end()){
            temp->next = NULL;
        }
        if (ump.find(curr->random) != ump.end()){
            temp->random = ump[curr->random];
        }
        if (ump.find(curr->random) == ump.end()){
            temp->random = NULL;
        }
        curr = curr->next;
    }
    return ump[head];
}
