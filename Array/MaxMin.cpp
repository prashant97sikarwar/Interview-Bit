//Problem Link:- https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    int mx = INT_MIN;
    int mn = INT_MAX;
    for(int i=0;i<A.size();i++){
        mn = min(mn,A[i]);
        mx = max(mx,A[i]);
    }
    return mn + mx;
}
