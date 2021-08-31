//Problem Link:- https://www.interviewbit.com/old/problems/word-ladder-i/

#include<bits/stdc++.h>
using namespace std;

int solve(string src, string dst, vector<string> &dict){
    unordered_set <string> lookUp;
    for(string& s : dict){
        lookUp.insert(s);
    }
    int step = 1;
    queue<string> pq;
    pq.push(src);
    while(!pq.empty()){
        int sz = pq.size();
        while (sz--){
            string word = pq.front();
            pq.pop();
            for(int i=0;i<word.length();i++){
                string key = word;
                for(int j=0;j<26;j++){
                    word[i] = 'a' + j;
                    if (word == key){
                        continue;
                    }
                    if (word == dst){
                        return step + 1;
                    }
                    if (lookUp.count(word)){
                        pq.push(word);
                        lookUp.erase(word);
                    }
                }
                word = key;
            }
        }
        step++;
    }
    return 0;
}