//Problem Link:- https://www.interviewbit.com/old/problems/clone-graph/

#include<bits/stdc++.h>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

void dfs(UndirectedGraphNode* node,UndirectedGraphNode* copyNode, unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>& visited){
    visited[node] = copyNode;
    for(auto child : node->neighbors){
        if (visited.find(child) == visited.end()){
            UndirectedGraphNode* copyChild = new UndirectedGraphNode(child->label);
            (copyNode->neighbors).push_back(copyChild);
            dfs(child,copyChild,visited);
        }
        else{
            (copyNode->neighbors).push_back(visited[child]);
        }
    }
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == NULL){
        return NULL;
    }
    UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> visited;
    visited[node] = copy;
    for(auto child : node->neighbors){
        if (visited.find(child) == visited.end()){
            UndirectedGraphNode* copyChild = new UndirectedGraphNode(child->label);
            (copy->neighbors).push_back(copyChild);
            dfs(child,copyChild,visited);
        }
        else{
            (copy->neighbors).push_back(visited[child]);
        }
    }
    return copy;

}
