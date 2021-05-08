//Problem Link:- https://www.interviewbit.com/problems/distribute-in-circle/

#include<bits/stdc++.h>
using namespace std;

int solve(int A, int B, int C) {
    int ans = (C-1+B+A)%B;
    if (ans == 0){
        return B;
    }
    return ans;
}
