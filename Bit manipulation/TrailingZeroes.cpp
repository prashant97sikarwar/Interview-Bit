//Problem Link:- https://www.interviewbit.com/problems/trailing-zeroes/

#include<bits/stdc++.h>
using namespace std;

int solve(int A) {
    long long num = A & (-A);
    int ans = 0;
    for(int i=0;i<=31;i++){
        if (num & (1 << i)){
            ans = i;
            break;
        }
    }
    return ans;
}

