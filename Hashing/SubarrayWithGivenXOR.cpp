//Problem Link:- https://www.interviewbit.com/problems/subarray-with-given-xor/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int k) {
    int n = nums.size();
    int sm = 0, res = 0;
    unordered_map<int,int> ump;
    ump[0] = 1;
    for(int i=0;i<n;i++){
        sm ^= nums[i];
        res += ump[sm^k];
        ump[sm]++;
    }
    return res;
}
