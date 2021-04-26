//Problem Link:- https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<string> &A) {
    vector<double> nums;
    sort(A.begin(),A.end());
    for(int i=0;i<A.size();i++){
        nums.push_back(stod(A[i]));
    }
    int l = 0;
    int p = 1;
    int r = A.size()-1;
    while(r>l and r>p){
        double sm = nums[l] + nums[p] + nums[r];
        if (sm > 1 && sm < 2){
            return 1;
        }
        else if (sm >= 2){
            r--;
        }
        else if (sm <= 1){
            p++;
        }
        if (p == nums.size()-1){
            l = l+1;
            p = l+1;
            r = nums.size()-1;
        }
    }
    return 0;
}