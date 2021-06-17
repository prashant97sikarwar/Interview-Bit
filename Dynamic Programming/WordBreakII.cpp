//Problem Link:- https://www.interviewbit.com/problems/word-break-ii/

#include<bits/stdc++.h>
using namespace std;

unordered_map<string,vector<string>> mp;

vector<string> helper(string s,unordered_set<string> nums){
    vector<string> result;
    if (mp.find(s) != mp.end()){
        return mp[s];
    }
    for(string w : nums){
        if (s.substr(0,w.length()) == w){
            if (w.length() == s.length()){
                result.push_back(w);
            }
            else{
                vector<string> temp = helper(s.substr(w.length()),nums);
                for(string str : temp){
                    result.push_back(w + " " + str);
                }
            }
        }
    }
    sort(result.begin(),result.end());
    mp[s] = result;
    return result;
}

vector<string> wordBreak(string s, vector<string> &A){
    mp.clear();
    unordered_set<string> nums;
    for(auto x : A){
        nums.insert(x);
    }
    return helper(s,nums);
}
