//Problem Link:- https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int a, int b, int c, int k){
    vector<int> nums = {a,b,c};
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(1);
    unordered_set<int> seen;
    vector<int> result;
    k++;
    while (k--){
        int cur_ugly = pq.top();
        pq.pop();
        result.push_back(cur_ugly);
        for(int i=0;i<nums.size();i++){
            if (seen.find(cur_ugly*nums[i]) == seen.end()){
                pq.push(cur_ugly*nums[i]);
                seen.insert(cur_ugly*nums[i]);
            }
        }
    }
    result.erase(result.begin());
    return result;
}
