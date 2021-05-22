//Problem Link:- https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

#include<bits/stdc++.h>
using namespace std;

string solve(string s) {
    queue<char> pq;
    unordered_map<char,int> ump;
    if (s.length() == 1){
        return s;
    }
    int n = s.length();
    string res;
    for(int i=0;i<n;i++){
        ump[s[i]]++;
        if (ump[s[i]] == 1){
            pq.push(s[i]);
            res.push_back(pq.front());
        }
        else{
            while (!pq.empty() && ump[pq.front()] > 1){
                pq.pop();
            }
            if (pq.empty()){
                res.push_back('#');
            }
            else{
                res.push_back(pq.front());
            }
        }
    }
    return res;
}
