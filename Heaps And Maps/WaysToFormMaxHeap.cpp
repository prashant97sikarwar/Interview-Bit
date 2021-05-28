//Problem Link:- https://www.interviewbit.com/problems/ways-to-form-max-heap/

#include<bits/stdc++.h>
using namespace std;

#define MAXN 105 
long long mod = 1000000007;
long long dp[MAXN]; 
long long nck[MAXN][MAXN]; 
long long logarithm[MAXN]; 

long long choose(long long n, long long k){
    if (k > n)
        return 0;
    if (n <= 1)
        return 1;
    if (k == 0)
        return 1;
  
    if (nck[n][k] != -1)
        return nck[n][k];
  
    long long answer = choose(n - 1, k - 1)%mod + choose(n - 1, k)%mod;
    nck[n][k] = answer%mod;
    return answer%mod;
}

long long getLeft(long long n){
    if (n == 1)
        return 0;
  
    long long h = logarithm[n];

    long long numh = (1 << h); 
    long long last = n - ((1 << h) - 1);
    if (last >= (numh / 2))
        return ((1 << h) - 1)%mod;
    else
        return ((1 << h) - 1 - ((numh / 2) - last))%mod;
}

long long numberOfHeaps(long long n){
    if (n <= 1)
        return 1;
  
    if (dp[n] != -1)
        return dp[n];
  
    long long left = getLeft(n);
    long long ans = (choose(n - 1, left)%mod * numberOfHeaps(left)%mod) * (numberOfHeaps(n - 1 - left)%mod)%mod;
    dp[n] = ans%mod;
    return ans%mod;
}

int solve(int n){
    for (long long i = 0; i <= n; i++)
        dp[i] = -1;
  
    for (long long i = 0; i <= n; i++)
        for (long long j = 0; j <= n; j++)
            nck[i][j] = -1;
  
    long long currLog2 = -1;
    long long currPower2 = 1;

    for (long long i = 1; i <= n; i++) {
        if (currPower2 == i) {
            currLog2++;
            currPower2 *= 2;
        }
        logarithm[i] = currLog2;
    }
    long long ans = numberOfHeaps(n)%mod;
    return (int)ans;
}
