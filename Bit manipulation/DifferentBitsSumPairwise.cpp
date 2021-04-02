//Problem Link:- https://www.interviewbit.com/problems/different-bits-sum-pairwise/

#include<bits/stdc++.h>
using namespace std;

int cntBits(vector<int> &arr) {
    int n = arr.size();
    long long res = 0;
    int MOD = 1e9 + 7;
    for(int i=0;i<=31;i++){
        int count = 0;
        for(int idx=0;idx<arr.size();idx++){
            if (arr[idx] & (1 << i)){
                count++;
            }
        }
        res += (((1LL)*count*(n-count)*2)%MOD);
        res %= MOD;
    }
    return res%MOD;
}
