//Problem Link:- https://www.interviewbit.com/problems/xor-ing-the-subarrays/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    int n = A.size();
    if (n%2 == 0)
        return 0;
    int res = 0;
    for(int i=0;i<n;i+=2){
        res ^= A[i];
    }
    return res;
}
