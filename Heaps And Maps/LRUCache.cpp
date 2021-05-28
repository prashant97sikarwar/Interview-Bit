//Problem Link:- https://www.interviewbit.com/problems/lru-cache/

#include<bits/stdc++.h>
using namespace std;


size_t sz;
list<pair<int,int>> dq;
unordered_map<int,list<pair<int,int>>::iterator> mp;


int get(int key){
    if (mp.find(key) == mp.end()){
        return -1;
    }
    int val = mp[key]->second;
    dq.erase(mp[key]);
    dq.push_front({key,val});
    mp[key] = dq.begin();
    return val;

}

void set(int key, int value) {
    if (mp.find(key) == mp.end()){
        if (dq.size() == sz){
            int key = dq.back().first;
            mp.erase(key);
            dq.pop_back();
        }
    }
    else{
        dq.erase(mp[key]);
    }
    dq.push_front({key,value});
    mp[key] = dq.begin();
    return;
}
