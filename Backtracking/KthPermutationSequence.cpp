//Problem Link:- https://www.interviewbit.com/problems/kth-permutation-sequence/

#include<bits/stdc++.h>
using namespace std;

vector<int> factorial(int n){
    vector<int> fact(n+1,0);
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2;i<=n;i++){
        if (i <= 12){
            fact[i] = i*fact[i-1];
        }
        else{
            fact[i] = INT_MAX;
        }
    }
    return fact;
}

string getPermutation(int n,int k) {
    vector<int> fact = factorial(n);
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        nums[i] = i+1;
    }
    n--;
    k--;
    string res = "";
    while(n >= 0){
        int idx = k / fact[n];
        k = k % fact[n];
        res += (to_string(nums[idx]));
        auto it = nums.begin();
        nums.erase(it+idx);
        n--;
    }
    return res;
}
