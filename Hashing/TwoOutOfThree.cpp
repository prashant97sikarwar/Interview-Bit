//Problem link:- https://www.interviewbit.com/problems/two-out-of-three/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    vector<int> f(100001,0);
    vector<int> s(100001,0);
    vector<int> t(100001,0);
    for(int i=0;i<A.size();i++){
        if (f[A[i]] == 0){
            f[A[i]] = 1;
        }
    }
    for(int i=0;i<B.size();i++){
        if (s[B[i]] == 0){
            s[B[i]] = 1;
        }
    }
    for(int i=0;i<C.size();i++){
        if (t[C[i]] == 0){
            t[C[i]] = 1;
        }
    }
    vector<int> res(100001,0);
    for(int i=1;i<=100000;i++){
        res[i] = f[i] + s[i] + t[i];
    }
    vector<int> ans;
    for(int i=1;i<=100000;i++){
        if (res[i] >= 2){
            ans.push_back(i);
        }
    }
    return ans;
    
}
