//Problem Link:- https://www.interviewbit.com/problems/maximum-absolute-difference/

#include<bits/stdc++.h>
using namespace std;

int maxArr(vector<int> &A) {
    vector<pair<int,int>> flag = {{1,1},{-1,1},{1,-1},{-1,-1}};
    int res = 0;
    for(auto cur : flag){
        int s1 = cur.first;
        int s2 = cur.second;
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int i=1;i<A.size()+1;i++){
            mx = max(mx,s1*A[i-1] + s2*i);
            mn = min(mn,s1*A[i-1] + s2*i);
        }
        res = max(res,mx-mn);
    }
    return res;
}
