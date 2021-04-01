//Problem Link:- https://www.interviewbit.com/problems/count-total-set-bits/

#include<bits/stdc++.h>
using namespace std;

int power(int a,int b){
    int res = 1;
    while (b > 0){
        if (b&1){
            res *= a;
            b-=1;
        }
        else{
            a *= a;
            b >>= 1;
        }
    }
    return res;
}


int solve(int A) {
    int bits = 0;
    for(int i=31;i>=0;i--){
        if (A & (1 << i)){
            bits = i+1;
            break;
        }
    }
    long long cnt = 0;
    long long MOD = 1e9 + 7;
    for(int i=1;i<=bits;i++){
        int di = power(2,i);
        int app = ((A+1) / di)*(di/2);
        cnt += (app%MOD);
        int rem = (A+1) % di;
        if (rem > di/2)
            cnt += (rem - di/2);
            cnt %= MOD;
    }
    return cnt%MOD;
}
