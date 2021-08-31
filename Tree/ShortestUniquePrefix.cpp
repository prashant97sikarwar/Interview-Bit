//Problem Link:- https://www.interviewbit.com/problems/shortest-unique-prefix/
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    unordered_map<char,TrieNode*> children;
    bool terminal;
    int cnt;
    
    TrieNode(char ch){
        data = ch;
        terminal = false;
        cnt = 1;
        
    }
};

void insert(TrieNode* root, string&s ){
    TrieNode* cur = root;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if (cur->children.count(ch)){
            cur = cur->children[ch];
            cur->cnt += 1;
        }
        else{
            TrieNode* child = new TrieNode(ch);
            cur->children[ch] = child;
            cur = child;
        }
    }
    cur->terminal = true;
}

void helper(string &s,TrieNode* root,vector<string>& result){
    TrieNode* cur = root;
    string prefix;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        cur = cur->children[ch];
        prefix.push_back(ch);
        if ((cur->cnt) <= 1){
            result.push_back(prefix);
            break;
        }
        else{
            continue;
        }
    }
}

vector<string> prefix(vector<string> &nums) {
    const int n = nums.size();
    TrieNode* root = new TrieNode(' ');
    for(string&s : nums){
        insert(root,s);
    }
    vector<string> result;
    for(string &s : nums){
        helper(s,root,result);
    }
    return result;
}
