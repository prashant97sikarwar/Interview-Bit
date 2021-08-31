//Problem Link:- https://www.interviewbit.com/problems/hotel-reviews/

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    if (a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solve(string A, vector<string> &B) {
    set<string> s;
    string str;
    for(int i=0;i<A.length();i++){
        if (A[i] == '_'){
            s.insert(str);
            str.clear();
        }
        else{
            str.push_back(A[i]);
        }
    }
    s.insert(str);
    vector<pair<int,int>> res;
    for(int i=0;i<B.size();i++){
        str = B[i];
        string t;
        int cnt = 0;
        for(int j=0;j<str.size();j++){
            if (str[j] == '_'){
                if (s.count(t)){
                    cnt++;
                }
                t.clear();
            }
            else{
                t.push_back(str[j]);
            }
        }
        if (s.count(t)){
            cnt++;
        }
        res.push_back({cnt,i});
    }
    sort(res.begin(),res.end(),cmp);
    vector<int> result;
    for(int i=0;i<res.size();i++){
        result.push_back(res[i].second);
    }
    return result;
}
