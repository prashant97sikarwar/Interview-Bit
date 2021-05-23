//Problem Link:- https://www.interviewbit.com/problems/pairs-with-given-xor/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int k) {
    int n = nums.size();
    set<int> s;
    int res = 0;
    for(int i=0;i<n;i++){
        if (s.find(nums[i] ^ k) != s.end()){
            res++;
        }
        s.insert(nums[i]);
    }
    return res;
}
