//Problem Link:- https://www.interviewbit.com/problems/subarray-with-equal-occurences/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int a, int b) {
    int n = nums.size();
    unordered_map<int,int> ump;
    ump[0] = 1;
    int sm = 0,res = 0;
    for(int i=0;i<n;i++){
        if (nums[i] == a){
            sm--;
        }
        if (nums[i] == b){
            sm++;
        }
        if (ump.find(sm) != ump.end()){
            res += ump[sm];
        }
        ump[sm]++;
    }
    return res;
}
